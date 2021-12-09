#include "UIBar.h"

void UIBar::SetPosition(Vector2 pos, Vector2 offset)
{
    _position.x = pos.x + offset.x;
    _position.y = pos.y + offset.y;
}

void UIBar::SetValue(float ratio)
{
    _ratio = ratio;
}


void UIBar::Draw ()
{
    // draw the background rectangle
    DrawRectangle(_position.x, _position.y, _width, _height, _backgroundColour);
    // draw the bar
    DrawRectangle(_position.x, _position.y, (_width * _ratio), _height, _barColour);
}           