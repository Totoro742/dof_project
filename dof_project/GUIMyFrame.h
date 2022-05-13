
#ifndef __GUI_MY_FRAME_H__
#define __GUI_MY_FRAME_H__

#include "GUI.h"

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/filefn.h> 
#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/dcbuffer.h>
#include <wx/filefn.h> 

class GUIMyFrame : public MyFrame {
protected:


public:
	GUIMyFrame(wxWindow* parent);
	wxImage image; 
	void click(wxCommandEvent& event);
	wxImage Img_Org, // tu bedzie przechowywany oryginalny obrazek
		Img_Cpy;        // wszystkie zmiany beda wykonywane na tej kopii obrazka

	void Repaint();

};
#endif // __GUI_MY_FRAME_H__