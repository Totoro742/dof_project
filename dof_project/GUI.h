///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
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
		wxButton* m_button3;
		wxSlider* m_slider1;
		wxStaticText* m_staticText1;
		wxSlider* m_slider2;
		wxStaticText* m_staticText2;
		wxCheckBox* m_checkBox1;
		wxPanel* m_panel1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void MyFrameOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_scrolledWindow( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void load_picture( wxCommandEvent& event ) { event.Skip(); }
		virtual void load_map( wxCommandEvent& event ) { event.Skip(); }
		virtual void save_image( wxCommandEvent& event ) { event.Skip(); }
		virtual void preview_mode( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame();
	
};

#endif //__GUI_H__
