
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}  // 构造函数
} Vector[100];
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
/*
α×β
若β在α的逆时针方向，则为正值、顺时针则为负值、两向量共线则为0
*/
double Cross(Vector A, Vector B) { return A.x * B.y - B.x * A.y; }
// 取模（求长度）(Length)
double Length(Vector A) { return sqrt(Dot(A, A)); }
// 计算两向量夹角(Angle)
double Angle(Vector A, Vector B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}
// 计算两向量构成的平行四边形有向面积(Area2)
double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }
// 计算向量逆时针旋转后的向量(Rotate)
Vector Rotate(Vector A, double rad) {
  return Vector(A.x * cos(rad) - A.y * sin(rad),
                A.x * sin(rad) + A.y * cos(rad));
}