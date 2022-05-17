
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
#include <vector>

class GUIMyFrame : public MyFrame {
protected:
	std::vector<wxImage> blurs_map;


public:
	GUIMyFrame(wxWindow* parent);
	wxImage image, map, edited_image;
	wxBitmap bitmap, buffer;
	void load_picture(wxCommandEvent& event);
	void load_map(wxCommandEvent& event);
	void repaint();
	void MyFrameOnPaint(wxPaintEvent& event);
	void m_scrolledWindow(wxUpdateUIEvent& event);
	void save_image(wxCommandEvent& event);
	void preview_mode(wxCommandEvent& event);
	void m_s_blur(wxScrollEvent& event);
	//void preview_mode(wxCommandEvent& event);

	void Blur_IMG();
	void Blur_Frames();




};
#endif // __GUI_MY_FRAME_H__