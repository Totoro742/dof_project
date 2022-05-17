///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	bSizer2->SetMinSize( wxSize( 200,-1 ) ); 
	picture_button = new wxButton( this, wxID_ANY, wxT("Load Picture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( picture_button, 0, wxALL|wxEXPAND|wxSHAPED, 5 );
	
	map_button = new wxButton( this, wxID_ANY, wxT("Load Map"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( map_button, 0, wxALL|wxEXPAND|wxSHAPED, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("Save Picture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_button3, 0, wxALL|wxEXPAND|wxSHAPED, 5 );
	
	m_slider1 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( m_slider1, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxBOTTOM, 5 );
	
	m_slider2 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( m_slider2, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Blur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxBOTTOM, 5 );
	
	m_checkBox1 = new wxCheckBox( this, wxID_ANY, wxT("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1->SetValue(true); 
	bSizer2->Add( m_checkBox1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,533 ), wxTAB_TRAVERSAL );
	bSizer3->Add( m_panel1, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer3, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::MyFrameOnPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::m_scrolledWindow ) );
	picture_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_picture ), NULL, this );
	map_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_map ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_image ), NULL, this );
	m_checkBox1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::preview_mode ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::MyFrameOnPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::m_scrolledWindow ) );
	picture_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_picture ), NULL, this );
	map_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_map ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_image ), NULL, this );
	m_checkBox1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::preview_mode ), NULL, this );
	
}
