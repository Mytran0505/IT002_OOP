#include<iostream>
#include<vector>

using namespace std;
struct Coordinate {
    double x;
    double y;
};
class Quadrangle
{
private:
    Coordinate Coor[4];
public:
    //constructor and destructor
    Quadrangle();
    Quadrangle(Coordinate* coor);
    virtual ~Quadrangle();

    //Setter
    void SetCoor(Coordinate coor[4]);
    virtual void Set();

    //Getter
    Coordinate* GetCoor() { return Coor; }

    //other methods
    virtual bool Check() = 0;
    virtual void Print();
};
class Trapeze :public Quadrangle
{
private:
    double LongEdge;
    double ShortEdge;
    double Heigth;
public:
    //Constructor and Destructor
    Trapeze();
    Trapeze(double l, double s, double h);
    ~Trapeze();
    //Setter
    void Set();
    void SetLongEdge(double w);
    void SetShortEdge(double l);
    void SetHeigth(double h);
    //Getter
    double GetLongEdge() { return LongEdge; }
    double GetShortEdge() { return ShortEdge; }
    double GetHeigth() { return Heigth; }
    //other method
    virtual bool Check();
    void Print();
};
class Parallelogram :public Quadrangle
{
private:
    double LongEdge;
    double ShortEdge;
    double Heigth;
public:
    //Constructor and Destructor
    Parallelogram();
    Parallelogram(double l, double s, double h);
    ~Parallelogram();
    //Setter
    void Set();
    void SetLongEdge(double w);
    void SetShortEdge(double l);
    void SetHeigth(double h);
    //Getter
    double GetLongEdge() { return LongEdge; }
    double GetShortEdge() { return ShortEdge; }
    double GetHeigth() { return Heigth; }
    //other method
    virtual bool Check();
    void Print();
};
class RecAngle :public Quadrangle
{
private:
    double Width;
    double Length;
public:
    //Constructor and Destructor
    RecAngle();
    RecAngle(double w, double l);
    ~RecAngle();
    //Setter
    void Set();
    void SetWidth(double w);
    void SetLength(double l);
    //Getter
    double GetWidth() { return Width; }
    double GetLength() { return Length; }
    //other method
    virtual bool Check();
    virtual void Print();
};
class Square :public RecAngle
{
private:
    double Edge;
public:
    //Constructor and Destructor
    Square();
    Square(double e);
    ~Square();
    //Setter
    void Set();
    void SetEdge(double e);
    //Getter
    double GetEdge() { return Edge; }
    //other method
    virtual bool Check();
    void Print();
};
Quadrangle::Quadrangle() {
    Coordinate c[4];
    for (int i = 0;i < 4;i++) {
        c[i].x = c[i].y = 0;
    }
    SetCoor(c);
}
Quadrangle::Quadrangle(Coordinate* coor) {
    SetCoor(coor);
}
Quadrangle::~Quadrangle() {
}
void Quadrangle::SetCoor(Coordinate coor[4]) {
    for (int i = 0;i < 4;i++) {
        Coor[i].x = coor[i].x;
        Coor[i].y = coor[i].y;
    }
}
void Quadrangle::Set() {
    Coordinate c[4];
    do {
        for (int i = 0;i < 4;i++) {
            cout << "Coordinate " << i + 1 << " (x,y): ";
            cin >> c[i].x >> c[i].y;
        }
        SetCoor(c);
    } while (this->Check() == 0);
}
void Quadrangle::Print() {
    Coordinate* c = GetCoor();
    for (int i = 0;i < 4;i++) {
        cout << "( " << c[i].x << " , " << c[i].y << ")";
        if (i != 3) {
            cout << "--";
        }
    }
}

//Trapeze definition
//Constructor and Destructor
Trapeze::Trapeze() {
    SetLongEdge(0);
    SetHeigth(0);
    SetShortEdge(0);
}
Trapeze::Trapeze(double l, double s, double h) {
    SetLongEdge(l);
    SetHeigth(h);
    SetShortEdge(s);
}
Trapeze::~Trapeze() {
}
//Setter
void Trapeze::Set() {
    cout << "Input Trapeze: " << endl;
    Quadrangle::Set();
}
void Trapeze::SetLongEdge(double w) {
    LongEdge = w;
}
void Trapeze::SetShortEdge(double l) {
    ShortEdge = l;
}
void Trapeze::SetHeigth(double h) {
    Heigth = h;
}

//other method
double MultiCoor(Coordinate c1, Coordinate c2) {
    return c1.x * c2.x + c1.y * c2.y;
}
double Module(Coordinate c1, Coordinate c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

Coordinate VectorCoor(Coordinate c1, Coordinate c2) {
    Coordinate c;
    c.x = c1.x - c2.x;
    c.y = c1.y - c2.y;
    return c;
}
bool Trapeze::Check() {
    Coordinate YAxis = { 0,1 };
    Coordinate* c = GetCoor();
    vector<double> value;
    double h;
    value.resize(0);

    for (int i = 0;i < 3;i++) {
        for (int j = i + 1;j < 4;j++) {
            if (MultiCoor(VectorCoor(c[i], c[j]), YAxis) == 0) {
                value.push_back(Module(c[i], c[j]));
                for (int k = 0;k < 4;k++) {
                    if (k != i && k != j) {
                        h = abs(c[k].y - c[i].y);
                    }
                }
            }
        }
    }
    if (value.size() != 2) {
        cout << "Wrong input!\n";
        return false;
    }
    else {
        SetLongEdge(value[0] > value[1] ? value[0] : value[1]);
        SetShortEdge(value[0] < value[1] ? value[0] : value[1]);
        SetHeigth(h);
        return true;
    }
}
void Trapeze::Print() {
    cout << "Trapeze: \n";
    Quadrangle::Print();
    cout << "\n\t-Long edge: " << GetLongEdge() << endl;
    cout << "\n\t-Short edge: " << GetShortEdge() << endl;
    cout << "\n\t-Heigth: " << GetHeigth() << endl;
}
//Parallelogram definition
//Constructor and Destructor
Parallelogram::Parallelogram() {
    SetLongEdge(0);
    SetShortEdge(0);
    SetHeigth(0);
}
Parallelogram::Parallelogram(double l, double s, double h) {
    SetLongEdge(l);
    SetShortEdge(s);
    SetHeigth(h);
}
Parallelogram::~Parallelogram() {
}
//Setter
void Parallelogram::Set() {
    cout << "Input Parallelogram:\n";
    Quadrangle::Set();
}
void Parallelogram::SetLongEdge(double w) {
    LongEdge = w;
}
void Parallelogram::SetShortEdge(double l) {
    ShortEdge = l;
}
void Parallelogram::SetHeigth(double h) {
    Heigth = h;
}
//other method
bool Parallelogram::Check() {
    Coordinate YAxis = { 0,1 };
    Coordinate* c = GetCoor();
    vector<double> value;
    double h;
    double s;
    value.resize(0);

    for (int i = 0;i < 3;i++) {
        for (int j = i + 1;j < 4;j++) {
            if (MultiCoor(VectorCoor(c[i], c[j]), YAxis) == 0) {
                value.push_back(Module(c[i], c[j]));
                for (int k = 0;k < 4;k++) {
                    if (k != i && k != j) {
                        h = abs(c[k].y - c[i].y);
                        double d1 = Module(c[k], c[i]);
                        double d2 = Module(c[k], c[j]);
                        s = (d1 < d2 ? d1 : d2);
                    }
                }
            }

        }
    }
    if (value.size() == 2 && value[0] == value[1]) {
        SetLongEdge(value[0] > s ? value[0] : s);
        SetShortEdge(value[0] < s ? value[0] : s);
        SetHeigth(h);
        return true;
    }
    else {
        cout << "Wrong input!\n";
        return false;
    }
}
void Parallelogram::Print() {
    cout << "Parallelogram: \n";
    Quadrangle::Print();
    cout << "\n\t-Long edge: " << GetLongEdge() << endl;
    cout << "\n\t-Short edge: " << GetShortEdge() << endl;
    cout << "\n\t-Heigth: " << GetHeigth() << endl;
}
//Recangle definition
//Constructor and Destructor
RecAngle::RecAngle() {
    SetWidth(0);
    SetLength(0);
}
RecAngle::RecAngle(double w, double l) {
    SetWidth(w);
    SetLength(l);
}
RecAngle::~RecAngle() {
}
//Setter
void RecAngle::Set() {
    cout << "Input recangle: ";
    Quadrangle::Set();
}
void RecAngle::SetWidth(double w) {
    Width = w;
}
void RecAngle::SetLength(double l) {
    Length = l;
}
//other method
bool RecAngle::Check() {
    Coordinate YAxis = { 0,1 };
    Coordinate XAxis = { 1,0 };
    Coordinate* c = GetCoor();
    vector<double> Xvalue;
    vector<double> Yvalue;
    Xvalue.resize(0);
    Yvalue.resize(0);
    for (int i = 0;i < 3;i++) {
        for (int j = i + 1;j < 4;j++) {
            if (MultiCoor(VectorCoor(c[i], c[j]), YAxis) == 0) {
                Xvalue.push_back(Module(c[i], c[j]));
            }
            else if (MultiCoor(VectorCoor(c[i], c[j]), XAxis) == 0) {
                Yvalue.push_back(Module(c[i], c[j]));
            }
            else {
            }
        }
    }
    if (Xvalue.size() == Yvalue.size()) {
        SetWidth(Xvalue[0] > Yvalue[0] ? Xvalue[0] : Yvalue[0]);
        SetLength(Xvalue[0] < Yvalue[0] ? Xvalue[0] : Yvalue[0]);
        return true;
    }
    else {
        cout << "Wrong input!\n";
        return false;
    }
}
void RecAngle::Print() {
    cout << "Recangle: \n";
    Quadrangle::Print();
    cout << "\n\t-Width: " << GetWidth() << endl;
    cout << "\n\t-Length: " << GetLength() << endl;
}


//Square definition
//Constructor and Destructor
Square::Square() {
    Edge = 0;
}
Square::Square(double e) {
    Edge = e;
}
Square::~Square() {
}
//Setter
void Square::Set() {
    cout << "Input Edge:\n";
    Quadrangle::Set();
}
void Square::SetEdge(double e) {
    Edge = e;
}
//other method
bool Square::Check() {
    if (RecAngle::Check() == 1 && RecAngle::GetLength() == RecAngle::GetWidth()) {
        SetEdge(RecAngle::GetLength());
        return true;
    }
    else {
        cout << "Wrong input!\n";
        return false;
    }
}
void Square::Print() {
    cout << "Square: \n";
    Quadrangle::Print();
    cout << "\n\tEdge: " << GetEdge();
}

void Input(vector<Quadrangle*>& List) {
    int CatchKey;
    do {
        cout << "\tPress 1 to input Trapeze.\n";
        cout << "\tPress 2 to input Parellelogram.\n";
        cout << "\tPress 3 to input RectAngle.\n";
        cout << "\tPress 4 to input Square.\n";
        cout << "\tPress 5 to back to the main menu.\n";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5)
        {
            cout << "Just Press in range 1,2,3,4,5. Again: ";
        }
        switch (CatchKey)
        {
        case 1:
            List.push_back(new Trapeze);
            List.back()->Set();
            break;
        case 2:
            List.push_back(new Parallelogram);
            List.back()->Set();
            break;
        case 3:
            List.push_back(new RecAngle);
            List.back()->Set();
            break;
        case 4:
            List.push_back(new Square);
            List.back()->Set();
            break;
        default:
            break;
        }
    } while (CatchKey != 5);
}
void Print(vector<Quadrangle*>& List) {
    cout << "-----Print List Quadrangle----\n";
    for (int i = 0;i < List.size();i++) {
        List[i]->Print();
        cout << endl;
    }
    cout << "--------------------------\n";
}
int main() {
    vector<Quadrangle*> ListQuadrangle;
    ListQuadrangle.resize(0);
    int CatchKey;
    do {
        cout << "Manage Quadrangle: \n";
        cout << "\tPress 1 to input one kind Quadrangle.\n";
        cout << "\tPress 2 to print all list of Quadrangles.\n";
        cout << "\tPress 3 to exit.\n";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3)
        {
            cout << "Just Press in range 1,2,3. Again: ";
        }
        switch (CatchKey)
        {
        case 1:
            Input(ListQuadrangle);
            break;
        case 2:
            Print(ListQuadrangle);
            break;
        default:
            break;
        }
    } while (CatchKey != 3);
    for (int i = 0;i < ListQuadrangle.size();i++) {
        delete ListQuadrangle[i];
    }
    cout << "Thanks!";
    return 0;
}