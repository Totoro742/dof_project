#include "GUIMyFrame.h"

GUIMyFrame::GUIMyFrame(wxWindow* parent) : MyFrame(parent) {

}

void GUIMyFrame::click(wxCommandEvent& event) {
	wxFileDialog saveFileDialog(this, "Choose a file", "", "", "All files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;
	image.AddHandler(new wxJPEGHandler);
	image.AddHandler(new wxPNGHandler);
	image.SaveFile(saveFileDialog.GetPath());
	bitmap = wxBitmap(image);
	std::unique_ptr<wxClientDC> clientDC(new wxClientDC(m_panel1));
	buffer = wxBitmap(m_panel1->GetSize()); // move to resize
	std::unique_ptr<wxBufferedDC> MyDC(new wxBufferedDC(clientDC.get(), buffer));

	MyDC->SetDeviceOrigin(m_panel1->GetSize().x / 2, m_panel1->GetSize().y / 2);

	MyDC->SetBackground(*wxWHITE_BRUSH);
	MyDC->Clear();
	MyDC->DrawBitmap(bitmap, m_panel1->GetSize().x / 2, m_panel1->GetSize().y / 2);

}