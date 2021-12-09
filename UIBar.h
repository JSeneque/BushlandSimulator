#include "raylib.h"

class UIBar
{
public:
    UIBar() {};
    ~UIBar() {};
    void Draw();
    void SetPosition(Vector2 pos, Vector2 offset);
    void SetValue(float ratio);

private:
    Vector2 _position {0,0};
    int _width {50};
    int _height {10};
    Color _barColour {RED};
    Color _borderColour {WHITE};
    Color _backgroundColour {BLACK};
    float _ratio {0};
};