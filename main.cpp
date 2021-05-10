#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;

class kd_node{
private:
    vector<double> point;
    vector<string> data;
    kd_node* parent;
    kd_node* left; 
    kd_node* right;
    int dim;

public:
    int getDim(){
        return dim;
    }
    vector<string> getData(){
        return data;
    }
    vector<double> getPoint(){
        return point;
    }
    kd_node* getRight(){
        return right;
    }
    kd_node* getLeft(){
        return left;
    }
    kd_node* getParent(){
        return parent;
    }

    void setDim(int dim){
        this->dim = dim;
    }
    void setData(vector<string> data){
        this->data = data;
    }
    void setPoint(vector<double> point){
        this->point = point;
    }
    void setRight(kd_node* right){
        this->right = right;
    }
    void setLeft(kd_node* left){
        this->left = left;
    }
    void setParent(kd_node* parent){
        this->parent = parent;
    }
};

class KDTree{
private:
    kd_node* root;

public:
    kd_node* getRoot(){
        return root;
    }
    void setRoot(kd_node* root){
        this->root = root;
    }
};

// Inserts a new node and returns root of modified tree
// The parameter depth is used to decide axis of comparison
kd_node *insertRec(kd_node *root, vector<double> point, vector<string> data, unsigned depth)
{
    // Tree is empty?
    int k = point.size();
    if (root == NULL){
        kd_node* temp = new kd_node;
        temp->setData(data);
        temp->setPoint(point);
        temp->setLeft(NULL);
        temp->setRight(NULL);
        return temp;
    }
    // Calculate current dimension (cd) of comparison
    unsigned dimencion = depth % k;

    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (point[dimencion] < (root->getPoint()[dimencion]))
        root->setLeft(insertRec(root->getLeft(), point, data, depth + 1));
    else
        root->setRight(insertRec(root->getRight(), point, data, depth + 1));
    return root;
}

// Function to insert a new point with given point in
// KD Tree and return new root. It mainly uses above recursive
// function "insertRec()"
kd_node* insert(kd_node *root, vector<double> point, vector<string> data)
{
    return insertRec(root, point, data, 0);
}

// A utility method to determine if two Points are same
// in K Dimensional space
bool arePointsSame(vector<double> point1, vector<double> point2)
{
    int k = point1.size();
    // Compare individual pointinate values
    for (int i = 0; i < k; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}

// Searches a Point represented by "point" in the K D tree.
// The parameter depth is used to determine current axis.
bool searchRec(kd_node* root, vector<double> point, unsigned depth)
{
    int k = point.size();
    // Base cases
    if (root == NULL)
        return false;
    if (arePointsSame(root->getPoint(), point))
        return true;

    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned dimencion = depth % k;

    // Compare point with root with respect to dimencion (Current dimension)
    if (point[dimencion] < root->getPoint()[dimencion])
        return searchRec(root->getLeft(), point, depth + 1);

    return searchRec(root->getRight(), point, depth + 1);
}

// Searches a Point in the K D tree. It mainly uses
// searchRec()
bool search(kd_node* root, vector<double> point)
{
    // Pass current depth as 0
    return searchRec(root, point, 0);
}

void printData(vector<string> data){
    cout << "ID: " << data[1] << endl;
    cout << "Nombre: " << data[2] << endl;
    cout << "Tamano en bytes: " << data[3] << endl;
    cout << "Moneda: " << data[4] << endl;
    cout << "Precio: " << data[5] << endl;
    cout << "Cantidad de resenas (Para todas las versiones): " << data[6] << endl;
    cout << "Cantidad de resenas (Para la version actual): " << data[7] << endl;
    cout << "Promedio de puntaje de las resenas (Para todas las versiones): " << data[8] << endl;
    cout << "Promedio de puntaje de las resenas (Para la version actual): " << data[9] << endl;
    cout << "Ultima version: " << data[10] << endl;
    cout << "Rating de contenido: " << data[11] << endl;
    cout << "Genero principal: " << data[12] << endl;
    cout << "Cantidad de dispositivos soportados: " << data[13] << endl;
    cout << "Cantidad de capturas de pantallas por dispositivos: " << data[14] << endl;
    cout << "Cantidad de lenguajes soportados: " << data[15] << endl;
    cout << "Licencia Vpp activada: " << data[16] << endl;
}

bool es_mayor(vector<double> actual, vector<double> mejor, vector<double> punto){
    float auxActual = (pow((punto[0] - actual[0]),2)) + (pow((punto[1] - actual[1]),2));
    auxActual = sqrt(auxActual);
    float auxMejor = (pow((punto[0] - mejor[0]),2)) + (pow((punto[1] - mejor[1]),2));
    auxMejor = sqrt(auxMejor);

    if(auxMejor == auxActual){
        return false;
    }
    else if(auxMejor < auxActual){
        return false;
    }
    
    return true;
}

vector<string> encontrarDatoNombre(kd_node* root, string filtro){
    stack<kd_node> S;
    kd_node actual;
    vector<string> data;
    S.push(*root);
	while(S.size() > 0){
        actual = S.top();
        S.pop();
        
        if(filtro.compare(actual.getData()[2]) == 0){
            data = actual.getData();
            return data;
        }

        S.push(*actual.getLeft());
        S.push(*actual.getRight());
    }
    return data;
}

// Driver program to test above functions
int main()
{
    kd_node* root = NULL;

    vector<string> datas2[] = {{"1","281656475","PAC-MAN Premium","100788224","USD","3.99","21292","26","4","4.5","6.3.5","4+","Games","38","5","10","1"}, {"6","283619399","Shanghai Mahjong","10485713","USD","0.99","8253","5516","4","4","1.8","4+","Games","47","5","1","1"}}; 
    vector<double> points2[] = {{100788224,3.99,21292,26,4,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,5,10,1}, {10485713,0.99,8253,5516,4,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,47,5,1,1}};  

    vector<string> datas[] = {{"3", "6"}, {"17", "15"}, {"13", "15"}, {"6", "12"},
                       {"9", "1"}, {"2", "7"}, {"10", "19"}}; 
    vector<double> points[] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};  
    for (int i=0; i<2; i++)
       root = insert(root, points2[i], datas2[i]);
  
    vector<double> point1 = {100788224,3.99,21292,26,4,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,5,10,1};
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n";
  
    vector<double> point2 = {10485713,0.99,8253,5516,4,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,47,5,1,1};
    (search(root, point2))? cout << "Found\n": cout << "Not Found\n";
    
    printData(encontrarDatoNombre(root, "PAC-MAN Premium"));

    return 0;
}
