class Solution {
public:
    double r, x, y;
    double getRandomNumber(double a, double r) {
        double random = -1 + ((double) rand() / (RAND_MAX))*2;
        return a + random*r;
    }
    Solution(double radius, double x_center, double y_center) {
        this->r = radius;
        this->x = x_center;
        this->y = y_center;
        srand(time(NULL));
    }
    
    vector<double> randPoint() {
        double X = getRandomNumber(this->x, this->r);
        double Y = getRandomNumber(this->y, this->r);
        while(pow((this->x - X), 2) + pow((this->y - Y), 2) >= r*r) {
            X = getRandomNumber(this->x, this->r);
            Y = getRandomNumber(this->y, this->r);
        }
        return {X,Y};
    }
};
