#include "GUIMyFrame.h"

GUIMyFrame::GUIMyFrame(wxWindow* parent) : MyFrame(parent) {
	this->SetBackgroundColour(wxColor(128, 128, 128));
	image.Create(m_panel1->GetSize());
	edited_image.Create(m_panel1->GetSize());
	image.SetRGB(wxRect(m_panel1->GetSize()), 255, 255, 255);
	edited_image.SetRGB(wxRect(m_panel1->GetSize()), 255, 255, 255);
}

void GUIMyFrame::load_picture(wxCommandEvent& event) {
	wxFileDialog loadFile(this, "Choose an image", "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (loadFile.ShowModal() == wxID_OK) {
		wxString path = loadFile.GetPath();
		image.AddHandler(new wxJPEGHandler);
		image.LoadFile(path, wxBITMAP_TYPE_JPEG);
		edited_image = image.Copy();
		Blur_Frames();
	}
}

void GUIMyFrame::load_map(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "Choose a map", "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (saveFileDialog.ShowModal() == wxID_OK) {
		wxString path = saveFileDialog.GetPath();
		map.AddHandler(new wxJPEGHandler);
		map.LoadFile(path, wxBITMAP_TYPE_JPEG);
		map = map.Blur(5);
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
	edited_image.SaveFile(saveFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
}

void GUIMyFrame::repaint() {
	std::unique_ptr<wxClientDC> clientDCimage(new wxClientDC(m_panel1));
	buffer = wxBitmap(m_panel1->GetSize());
	std::unique_ptr<wxBufferedDC> imageDC(new wxBufferedDC(clientDCimage.get(), buffer));
	imageDC->SetDeviceOrigin(0, 0);
	imageDC->SetBackground(*wxBLACK_BRUSH);
	imageDC->Clear();
	wxImage tmp;
	if (edited_image.Ok()) {
		if (m_checkBox1->IsChecked()) {
			tmp = image;
			tmp.Rescale(m_panel1->GetSize().GetWidth(), m_panel1->GetSize().GetHeight());
		}
		else {
			tmp = edited_image;
			tmp.Rescale(m_panel1->GetSize().GetWidth(), m_panel1->GetSize().GetHeight());
		}
		imageDC->DrawBitmap(wxBitmap(tmp), wxPoint(0, 0));
	}
}
void GUIMyFrame::preview_mode(wxCommandEvent& event) {
	;
}

void GUIMyFrame::Blur_IMG() {
	edited_image = image.Copy();

	unsigned char *cpy_ptr = edited_image.GetData();
	unsigned char *map_ptr = map.GetData();

	int hight = edited_image.GetSize().GetHeight();
	int width = edited_image.GetSize().GetWidth();

	int depth = (slider_depth->GetValue() / 100.f) * 255;
	float blur = 1.f - slider_blur->GetValue() / 100.f;

	for (int j = 0; j < hight; j++)
	{
		for (int i = 0; i < width; i++) {
			int d = abs(depth - map_ptr[j*width * 3 + i * 3 ]);
			for (int k = 0; k < 3; k++) {

				int f = (blur_maps.size() - blur * (blur_maps.size() - 1)) - 1;
				if (f < 0) f = 0;
				int index = d / 255.f * f;
				cpy_ptr[j*width * 3 + i * 3 + k] = blur_maps.at(index).GetData()[j*width * 3 + i * 3 + k];
			}
		}
	}

}

void GUIMyFrame::Blur_Frames() {
	blur_maps.clear();
	for (int i = 0; i <+ 20; i++) {
		blur_maps.push_back(edited_image.Blur(i));
	}
}

void GUIMyFrame::m_s_blur(wxScrollEvent& event) {
	if ( image.IsOk() && map.IsOk() && image.GetSize()==map.GetSize())
		Blur_IMG();
	repaint();
}

void GUIMyFrame::Contrast(int value, unsigned char& p) {
	value = value * 2 - 100;
	double c = (100.0 + value) / (101.0 - value);
	int temp = c * (p - 127) + 127;
	if (temp < 0)
		p = 0;
	else if (temp > 255)
		p = 255;
	else
		p = temp;
}

void GUIMyFrame::Contrast(int value, unsigned char& p) {
	value = value * 2 - 100;
	unsigned char temp = p + value;
	if (temp > 255)
		temp = 255;
	else if (temp < 0)
		temp = 0;
	p = temp;
}

void GUIMyFrame::Gamma(int value, unsigned char& p) {

	float gamma = value / 50.f;
	p = 255.f*pow(p / 255.f, 1.f / gamma);
}

void GUIMyFrame::MyFrameOnPaint(wxPaintEvent& event) {
	repaint();
}
void GUIMyFrame::m_scrolledWindow(wxUpdateUIEvent& event) {
	repaint();
}

void GUIMyFrame::button_resetOnButtonClick(wxCommandEvent& event){
	slider_gamma->SetValue(50);
	slider_brightness->SetValue(50);
	slider_contrast->SetValue(50);
}
