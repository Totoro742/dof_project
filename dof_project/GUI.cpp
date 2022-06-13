///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 981,623 ), wxDefaultSize );

	wxBoxSizer* main_sizer;
	main_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* main_sizer2;
	main_sizer2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* menu_sizer;
	menu_sizer = new wxBoxSizer( wxVERTICAL );

	menu_sizer->SetMinSize( wxSize( 100,-1 ) );
	picture_button = new wxButton( this, wxID_ANY, wxT("Load Picture"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_sizer->Add( picture_button, 0, wxALL|wxEXPAND|wxSHAPED, 5 );

	map_button = new wxButton( this, wxID_ANY, wxT("Load Map"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_sizer->Add( map_button, 0, wxALL|wxEXPAND|wxSHAPED, 5 );

	save_button = new wxButton( this, wxID_ANY, wxT("Save Picture"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_sizer->Add( save_button, 0, wxALL|wxEXPAND|wxSHAPED, 5 );

	wxBoxSizer* bitmaps_sizer;
	bitmaps_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	text_first = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER|wxTE_PROCESS_ENTER );
	#ifdef __WXGTK__
	if ( !text_first->HasFlag( wxTE_MULTILINE ) )
	{
	text_first->SetMaxLength( 2 );
	}
	#else
	text_first->SetMaxLength( 2 );
	#endif
	text_first->SetMinSize( wxSize( 30,20 ) );

	bSizer14->Add( text_first, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("First bitmap"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer14->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bitmaps_sizer->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	text_last = new wxTextCtrl( this, wxID_ANY, wxT("20"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER|wxTE_PROCESS_ENTER );
	#ifdef __WXGTK__
	if ( !text_last->HasFlag( wxTE_MULTILINE ) )
	{
	text_last->SetMaxLength( 2 );
	}
	#else
	text_last->SetMaxLength( 2 );
	#endif
	text_last->SetMinSize( wxSize( 30,20 ) );

	bSizer15->Add( text_last, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Last bitmap"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer15->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bitmaps_sizer->Add( bSizer15, 1, wxEXPAND, 5 );


	menu_sizer->Add( bitmaps_sizer, 0, wxEXPAND, 5 );

	slider_depth = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	menu_sizer->Add( slider_depth, 0, wxALL|wxEXPAND, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	menu_sizer->Add( m_staticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	slider_blur = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	menu_sizer->Add( slider_blur, 0, wxALL|wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Blur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	menu_sizer->Add( m_staticText2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_checkBox1 = new wxCheckBox( this, wxID_ANY, wxT("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_sizer->Add( m_checkBox1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), wxLI_HORIZONTAL );
	m_staticline1->SetMinSize( wxSize( 100,-1 ) );

	menu_sizer->Add( m_staticline1, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* menu_sizer2;
	menu_sizer2 = new wxBoxSizer( wxVERTICAL );

	button_reset = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	menu_sizer2->Add( button_reset, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	slider_brightness = new wxSlider( this, wxID_ANY, 0, -255, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer16->Add( slider_brightness, 0, wxALL|wxEXPAND, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer16->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	menu_sizer2->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	slider_contrast = new wxSlider( this, wxID_ANY, 0, -255, 255, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( slider_contrast, 0, wxALL|wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Contrast"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer17->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	menu_sizer2->Add( bSizer17, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	slider_gamma = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer18->Add( slider_gamma, 0, wxALL|wxEXPAND, 5 );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("Gamma"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer18->Add( m_staticText81, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	menu_sizer2->Add( bSizer18, 1, wxEXPAND, 5 );


	menu_sizer->Add( menu_sizer2, 0, wxEXPAND, 5 );


	main_sizer2->Add( menu_sizer, 0, wxEXPAND, 5 );

	wxBoxSizer* panel_sizer;
	panel_sizer = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,640 ), wxTAB_TRAVERSAL );
	panel_sizer->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	main_sizer2->Add( panel_sizer, 1, wxALL|wxEXPAND, 5 );


	main_sizer->Add( main_sizer2, 1, wxEXPAND, 5 );


	this->SetSizer( main_sizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::MyFrameOnPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::m_scrolledWindow ) );
	picture_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_picture ), NULL, this );
	map_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_map ), NULL, this );
	save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_image ), NULL, this );
	text_first->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::text_firstOnTextEnter ), NULL, this );
	text_last->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::text_lastOnTextEnter ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	m_checkBox1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::preview_mode ), NULL, this );
	button_reset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::button_resetOnButtonClick ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::MyFrameOnPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::m_scrolledWindow ) );
	picture_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_picture ), NULL, this );
	map_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_map ), NULL, this );
	save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_image ), NULL, this );
	text_first->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::text_firstOnTextEnter ), NULL, this );
	text_last->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::text_lastOnTextEnter ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_depth->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	slider_blur->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::m_s_blur ), NULL, this );
	m_checkBox1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::preview_mode ), NULL, this );
	button_reset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::button_resetOnButtonClick ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_brightness->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_brightnessOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_contrast->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_contrastOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );
	slider_gamma->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_gammaOnScroll ), NULL, this );

}
