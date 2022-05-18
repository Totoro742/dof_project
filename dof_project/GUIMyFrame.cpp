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
	wxFileDialog saveFileDialog(this, "Save file", "", "", "JPG files (*.jpg)|*.jpg", wxFD_SAVE);
	if (saveFileDialog.ShowModal() == wxID_OK && edited_image.IsOk()) {
		wxString path = saveFileDialog.GetPath();
		edited_image.SaveFile(path, saveFileDialog.GetFilename());
	}
}

void GUIMyFrame::repaint() {
	std::unique_ptr<wxClientDC> clientDCimage(new wxClientDC(m_panel1));
	buffer = wxBitmap(m_panel1->GetSize());
	std::unique_ptr<wxBufferedDC> imageDC(new wxBufferedDC(clientDCimage.get(), buffer));
	imageDC->SetDeviceOrigin(0, 0);
	imageDC->SetBackground(*wxBLACK_BRUSH);
	imageDC->Clear();

	wxImage tmp = edited_image;
	if (tmp.Ok()) {
		tmp.Rescale(m_panel1->GetSize().GetWidth(), m_panel1->GetSize().GetHeight());

		imageDC->DrawBitmap(wxBitmap(tmp), wxPoint(0, 0));
	}
}

void GUIMyFrame::preview_mode(wxCommandEvent& event) {

}

void GUIMyFrame::Blur_IMG() {
	edited_image = image.Copy();

	unsigned char *cpy_ptr = edited_image.GetData();
	unsigned char *map_ptr = map.GetData();

	int hight = edited_image.GetSize().GetHeight();
	int width = edited_image.GetSize().GetWidth();

	int depth = (m_slider1->GetValue() / 100.f) * 255;
	float blur = 1.f - m_slider2->GetValue() / 100.f;

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



void GUIMyFrame::MyFrameOnPaint(wxPaintEvent& event) {
	repaint();
}
void GUIMyFrame::m_scrolledWindow(wxUpdateUIEvent& event) {
	repaint();
}