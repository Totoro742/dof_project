
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
#include <wx/wfstream.h>
#include <vector>
#include <functional>

class GUIMyFrame : public MyFrame {
protected:
	std::vector<wxImage> blur_maps;


public:
	GUIMyFrame(wxWindow* parent);
	wxImage image, map, image_blured, image_transformed;
	wxBitmap bitmap, buffer;
	void load_picture(wxCommandEvent& event);
	void load_map(wxCommandEvent& event);
	void repaint();
	void MyFrameOnPaint(wxPaintEvent& event);
	void m_scrolledWindow(wxUpdateUIEvent& event);
	void save_image(wxCommandEvent& event);
	void m_s_blur(wxScrollEvent& event);
	void button_resetOnButtonClick(wxCommandEvent& event);
	void text_firstOnTextEnter(wxCommandEvent& event);
	void text_lastOnTextEnter(wxCommandEvent& event);
	void slider_brightnessOnScroll(wxScrollEvent& event);
	void slider_contrastOnScroll(wxScrollEvent& event);
	void slider_gammaOnScroll(wxScrollEvent& event);


	
	void Blur_IMG();
	void Blur_Frames();
	void Transform(float value,std::function<float(float, unsigned char)> transformation);
	
};
#endif // __GUI_MY_FRAME_H__