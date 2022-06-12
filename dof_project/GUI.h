///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:

	protected:
		wxButton* picture_button;
		wxButton* map_button;
		wxButton* save_button;
		wxTextCtrl* text_first;
		wxStaticText* m_staticText5;
		wxTextCtrl* text_last;
		wxStaticText* m_staticText6;
		wxSlider* slider_depth;
		wxStaticText* m_staticText1;
		wxSlider* slider_blur;
		wxStaticText* m_staticText2;
		wxCheckBox* m_checkBox1;
		wxStaticLine* m_staticline1;
		wxButton* button_reset;
		wxSlider* slider_brightness;
		wxStaticText* m_staticText7;
		wxSlider* slider_contrast;
		wxStaticText* m_staticText8;
		wxSlider* slider_gamma;
		wxStaticText* m_staticText81;
		wxPanel* m_panel1;

		// Virtual event handlers, override them in your derived class
		virtual void MyFrameOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_scrolledWindow( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void load_picture( wxCommandEvent& event ) { event.Skip(); }
		virtual void load_map( wxCommandEvent& event ) { event.Skip(); }
		virtual void save_image( wxCommandEvent& event ) { event.Skip(); }
		virtual void text_firstOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void text_lastOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_s_blur( wxScrollEvent& event ) { event.Skip(); }
		virtual void preview_mode( wxCommandEvent& event ) { event.Skip(); }
		virtual void button_resetOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void slider_brightnessOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void slider_contrastOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void slider_gammaOnScroll( wxScrollEvent& event ) { event.Skip(); }


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 981,623 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

