//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include <wx/sizer.h>
#endif

/** Forward declarations. */
class wxRenderFrame;

/**
 * Application render panel.
 */
class wxRenderPanel : public wxPanel
{
    friend class wxRenderFrame;

public:
    /**
     * Default constructor.
     * @param parent - Parent render frame component
     */
    wxRenderPanel(wxRenderFrame* parent);

private:
    /**
     * Called by the render frame when panel need to be tick.
     */
    void TickNow();

    /**
     * Called by the system of by wxWidgets when the panel needs to be redrawn.
     * You can also trigger this call by calling Refresh()/Update().
     * @param evt - Paint event.
     */
    void TickEvent(wxPaintEvent& evt);

    /**
     * Actual rendering.
     * @param dc - Drawing context.
     */
    void Tick(wxDC& dc);

    /** Reference to parent render frame. */
    wxRenderFrame* _renderFrame;

    /** Declare event table for this panel class. */
    DECLARE_EVENT_TABLE();
};
