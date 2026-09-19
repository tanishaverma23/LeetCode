class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on/in the rectangle to the circle's center
        int nearestX = max(x1, min(xCenter, x2));
        int nearestY = max(y1, min(yCenter, y2));
        
        // Calculate squared distance from closest point to circle center
        int dx = xCenter - nearestX;
        int dy = yCenter - nearestY;
        
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};