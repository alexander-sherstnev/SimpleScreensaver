//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "wx/wxRenderContext.h"
#include "Core.h"

#define FloatColorToRGB(c) std::max(0, std::min(255, (int)floor(c * 256.0)))
#define ColorToWxColour(c) wxColour(FloatColorToRGB(c.r), FloatColorToRGB(c.g), FloatColorToRGB(c.b), FloatColorToRGB(c.a))
#define ColorToWxBrush(c) wxBrush(ColorToWxColour(c))
#define ColorToWxPen(c) wxPen(ColorToWxColour(c))

wxRenderContext::wxRenderContext(wxDC& dc) : _dc(dc)
{
}

void wxRenderContext::Clear()
{
    _dc.Clear();
}

void wxRenderContext::SetBackgroundColor(const Color& color)
{
    _dc.SetBackground(ColorToWxBrush(color));
}

void wxRenderContext::SetOutlineColor(const Color& color)
{
    _dc.SetPen(ColorToWxPen(color));
}

void wxRenderContext::SetFillColor(const Color& color)
{
    _dc.SetBrush(ColorToWxBrush(color));
}

void wxRenderContext::DrawPoint(const Point& point)
{
    _dc.DrawPoint(point);
}

void wxRenderContext::DrawPolygon(const Point points[], int size)
{
    _dc.DrawPolygon(size, points);
}