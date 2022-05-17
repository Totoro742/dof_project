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




void GUIMyFrame::MyFrameOnPaint(wxPaintEvent& event) {
	repaint();
}
void GUIMyFrame::m_scrolledWindow(wxUpdateUIEvent& event) {
	repaint();
}