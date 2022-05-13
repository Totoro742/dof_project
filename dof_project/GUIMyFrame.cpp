#include "GUIMyFrame.h"

GUIMyFrame::GUIMyFrame(wxWindow* parent) : MyFrame(parent) {

}

void GUIMyFrame::click(wxCommandEvent& event) {
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""));
	if (WxOpenFileDialog.ShowModal() == wxID_OK) {

	}
	wxImage::AddHandler(new wxJPEGHandler);          
	wxImage::AddHandler(new wxPNGHandler);
	wxImage image;


	if (!image.LoadFile(WxOpenFileDialog.GetPath())) {
		wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowa\u0107 obrazka"));
	}
	else {
		wxMessageBox(_("jestem zajebisty"));
		
		Img_Org = image.Copy();              // Kopiujemy obrazek do Img_Org
		Img_Cpy = Img_Org.Copy(); // Kopiujemy obrazek do Img_Cpy
	}
}


void GUIMyFrame::Repaint()
{
	//wxBitmap bitmap(Img_Cpy);          // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
	//wxClientDC dc(m_scrolledWindow);   // Pobieramy kontekst okna
	//m_scrolledWindow->DoPrepareDC(dc); // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
	//dc.DrawBitmap(bitmap, 0, 0, true); // Rysujemy bitmape na kontekscie urzadzenia
}