#include "GUIMyFrame.h"

GUIMyFrame::GUIMyFrame(wxWindow* parent) : MyFrame(parent) {
	this->SetBackgroundColour(wxColor(128, 128, 128));
	image.Create(m_panel1->GetSize());
	image.SetRGB(wxRect(m_panel1->GetSize()), 255, 255, 255);
}

void GUIMyFrame::load_picture(wxCommandEvent& event) {
	wxFileDialog loadFile(this, "Choose an image", "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (loadFile.ShowModal() == wxID_OK) {
		wxString path = loadFile.GetPath();
		image.AddHandler(new wxJPEGHandler);
		image.LoadFile(path, wxBITMAP_TYPE_JPEG);
	}
}

void GUIMyFrame::load_map(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "Choose a map", "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (saveFileDialog.ShowModal() == wxID_OK) {
		wxString path = saveFileDialog.GetPath();
		map.AddHandler(new wxJPEGHandler);
		map.LoadFile(path, wxBITMAP_TYPE_JPEG);
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

	wxImage tmp = image.Copy();
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

	int h = edited_image.GetSize().GetHeight();
	int w = edited_image.GetSize().GetWidth();

	float x = m_slider1->GetValue() / 100.f;
	float y = 1.f - m_slider2->GetValue() / 100.f;

	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++) {
			for (int k = 0; k < 3; k++) {

				int c = x * 255;
				int d = abs(c - map_ptr[j*w * 3 + i * 3 + k]);
				int f = (blurs_map.size() - y * (blurs_map.size() - 1)) - 1;
				if (f < 0) f = 0;
				int s = d / 255.f * f;
				cpy_ptr[j*w * 3 + i * 3 + k] = blurs_map[s].GetData()[j*w * 3 + i * 3 + k];
			}
		}
	}

}

void GUIMyFrame::Blur_Frames() {
	for (int i = 0; i < 10; i++) {
		blurs_map.push_back(edited_image.Copy().Blur(i));
	}
}



void GUIMyFrame::MyFrameOnPaint(wxPaintEvent& event) {
	repaint();
}
void GUIMyFrame::m_scrolledWindow(wxUpdateUIEvent& event) {
	repaint();
}