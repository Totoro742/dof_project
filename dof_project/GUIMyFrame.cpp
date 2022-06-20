#include "GUIMyFrame.h"


float limit(float v);
inline float Contrast(float value, unsigned char p);
inline float Brightnes(float value, unsigned char p);
inline float Gamma(float value, unsigned char p);



inline float limit(float v) {
	if (v > 255) return 255;
	else if (v < 0) return 0;
	return v;
}

inline float Contrast(float value, unsigned char p) {
	return limit(value * (p - 127) + 127);
}

inline float Brightnes(float value, unsigned char p) {
	return limit(p + value);
}

inline float Gamma(float value, unsigned char p) {
	return 255.f*pow(p / 255.f, value);
}

GUIMyFrame::GUIMyFrame(wxWindow* parent) : MyFrame(parent) {
	this->SetBackgroundColour(wxColor(128, 128, 128));
	image.Create(m_panel1->GetSize());
	image_final.Create(m_panel1->GetSize());
	image.SetRGB(wxRect(m_panel1->GetSize()), 255, 255, 255);
	image_final.SetRGB(wxRect(m_panel1->GetSize()), 255, 255, 255);
	repaint();
}

void GUIMyFrame::load_picture(wxCommandEvent& event) {
	wxFileDialog loadFile(this, "Choose an image", "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (loadFile.ShowModal() == wxID_OK) {
		wxString path = loadFile.GetPath();
		image.AddHandler(new wxJPEGHandler);
		image.LoadFile(path, wxBITMAP_TYPE_JPEG);
		Blur_Frames();
		image_transformed = image.Copy();
		image_final = image.Copy();
		repaint();
	}
}

void GUIMyFrame::load_map(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "Choose a map", "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (saveFileDialog.ShowModal() == wxID_OK) {
		wxString path = saveFileDialog.GetPath();
		map.AddHandler(new wxJPEGHandler);
		map.LoadFile(path, wxBITMAP_TYPE_JPEG);
		map = map.Blur(5);
		repaint();
	}
	
}

void GUIMyFrame::save_image(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "Save file", "", "", "JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;
	wxFileOutputStream outputStream(saveFileDialog.GetPath());
	if (!outputStream.IsOk())
	{
		wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
		return;
	}
	image_final.SaveFile(saveFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
}

void GUIMyFrame::repaint() {
	std::unique_ptr<wxClientDC> clientDCimage(new wxClientDC(m_panel1));
	buffer = wxBitmap(m_panel1->GetSize());
	std::unique_ptr<wxBufferedDC> imageDC(new wxBufferedDC(clientDCimage.get(), buffer));
	imageDC->SetDeviceOrigin(0, 0);
	imageDC->SetBackground(*wxBLACK_BRUSH);
	imageDC->Clear();
	wxImage tmp;
	
	if (image_final.Ok()) {
		if (m_checkBox1->IsChecked()) {
			tmp = image;
			tmp.Rescale(m_panel1->GetSize().GetWidth(), m_panel1->GetSize().GetHeight());
		}
		else {
			tmp = image_final;
			tmp.Rescale(m_panel1->GetSize().GetWidth(), m_panel1->GetSize().GetHeight());
		}
		imageDC->DrawBitmap(wxBitmap(tmp), wxPoint(0, 0));
	}
}


void GUIMyFrame::Blur_IMG() {

	unsigned char *cpy_ptr = image_blured.GetData();
	unsigned char *map_ptr = map.GetData();

	int hight = image_blured.GetSize().GetHeight();
	int width = image_blured.GetSize().GetWidth();

	int depth = (slider_depth->GetValue() / 100.f) * 255;
	float blur = 1.f - slider_blur->GetValue() / 100.f;

	for (int j = 0; j < hight; j++)
	{
		for (int i = 0; i < width; i++) {
			int d = abs(depth - map_ptr[j*width * 3 + i * 3 ]);

			int f = (blur_maps.size() - blur * (blur_maps.size() - 1)) - 1;
			if (f < 0) f = 0;
			int index = d / 255.f * f;

			for (int k = 0; k < 3; k++) {
				cpy_ptr[j*width * 3 + i * 3 + k] = blur_maps.at(index).GetData()[j*width * 3 + i * 3 + k];
			}
		}
	}

}

void GUIMyFrame::Blur_Frames() {
	image_blured = image.Copy();
	blur_maps.clear();
	wxString first_str = text_first->GetValue();
	wxString last_str = text_last->GetValue();
	int first = wxAtoi(first_str);
	int last = wxAtoi(last_str);
	for (int i = first; i <= last; i++) {
		blur_maps.push_back(image_blured.Blur(i));
	}
}

void GUIMyFrame::m_s_blur(wxScrollEvent& event) {
	if ( image.IsOk() && map.IsOk() && image.GetSize()==map.GetSize())
		Blur_IMG();
	image_transformed = image_blured.Copy();
	image_final = image_blured.Copy();
	
	repaint();
}




void GUIMyFrame::Transform(float value, std::function<float(float, unsigned char)> transformation, char flag) {

	if (!image_blured.IsOk() || !image.IsOk()) return;


	if (flag != t_flag) {
		image_transformed = image_final.Copy() ;
		t_flag = flag;
	}
	

	unsigned char* transform_ptr = image_transformed.GetData();
	unsigned char* final_ptr = image_final.GetData();
	for (int i = 0; i < 3 * image.GetSize().GetWidth() * image.GetSize().GetHeight(); i++) {
		final_ptr[i] = transformation(value, transform_ptr[i]);
	}
}

void GUIMyFrame::slider_brightnessOnScroll(wxScrollEvent& event) {
	Transform(slider_brightness->GetValue(), Brightnes,'b');
	repaint();
}
void GUIMyFrame::slider_contrastOnScroll(wxScrollEvent& event) {
	float c = (259.f / 255.f)*(255.f + slider_contrast->GetValue()) / (259.f - slider_contrast->GetValue());
	Transform(c, Contrast,'c');
	repaint();
}
void GUIMyFrame::slider_gammaOnScroll(wxScrollEvent& event) {
	float gamma = slider_gamma->GetValue()  / 50.f;
	Transform(gamma, Gamma,'g');
	repaint();
}

void GUIMyFrame::button_resetOnButtonClick(wxCommandEvent& event){
	slider_gamma->SetValue(50);
	slider_brightness->SetValue(0);
	slider_contrast->SetValue(0);
	image_transformed = image_blured.Copy();
	image_final = image_transformed.Copy();
	repaint();
}

void GUIMyFrame::button_applyOnButtonClick(wxCommandEvent& event){
	if (wxAtoi(text_first->GetValue()) > wxAtoi(text_last->GetValue()))
		text_first->ChangeValue(text_last->GetValue());
	if (!image_blured.IsOk() || !image.IsOk()) return;
	Blur_Frames();
}

void GUIMyFrame::preview_mode(wxCommandEvent& event) {
	repaint();
}
