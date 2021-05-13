#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class kd_node{
private:
    vector<double> point;
    vector<string> data;
    kd_node* parent;
    kd_node* left; 
    kd_node* right;
    unsigned depth;

public:
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
    unsigned getDepth(){
        return depth;
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
    void setDepth(unsigned depth){
        this->depth = depth;
    }
};

class KDTree{
private:
    kd_node root;

public:
    KDTree(kd_node raiz) : root(raiz){}
    kd_node getRoot(){
        return root;
    }
    void setRoot(kd_node root){
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
        temp->setDepth(depth);
        temp->setLeft(NULL);
        temp->setRight(NULL);
        return temp;
    }
    // Calculate current dimension (cd) of comparison
    unsigned dim = depth % k;

    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (point[dim] < (root->getPoint()[dim]))
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

void printData(kd_node data){
    cout << "ID: " << data.getData()[0] << endl;
    cout << "Nombre: " << data.getData()[1] << endl;
    cout << "Tamano en bytes: " << data.getData()[2] << endl;
    cout << "Moneda: " << data.getData()[3] << endl;
    cout << "Precio: " << data.getData()[4] << endl;
    cout << "Cantidad de resenas (Para todas las versiones): " << data.getData()[5] << endl;
    cout << "Cantidad de resenas (Para la version actual): " << data.getData()[6] << endl;
    cout << "Promedio de puntaje de las resenas (Para todas las versiones): " << data.getData()[7] << endl;
    cout << "Promedio de puntaje de las resenas (Para la version actual): " << data.getData()[8] << endl;
    cout << "Ultima version: " << data.getData()[9] << endl;
    cout << "Rating de contenido: " << data.getData()[10] << endl;
    cout << "Genero principal: " << data.getData()[11] << endl;
    cout << "Cantidad de dispositivos soportados: " << data.getData()[12] << endl;
    cout << "Cantidad de capturas de pantallas por dispositivos: " << data.getData()[13] << endl;
    cout << "Cantidad de lenguajes soportados: " << data.getData()[14] << endl;
    cout << "Licencia Vpp activada: " << data.getData()[15] << endl;
}

double distancia(vector<double> punt1, vector<double> punt2){
    double distancia = 0;
    bool igual = false;

    //size_bytes
    distancia=+abs(punt1[0] - punt2[0]);
    //price
    if(abs(punt1[1] - punt2[1]) > 10)
        distancia=+9;
    //rating_count_tot
    if(abs(punt1[2] - punt2[2]) > 3500)
        distancia=+6;
    //rating_count_ver
    if(abs(punt1[3] - punt2[3]) > 2500)
        distancia=+5.5;
    //user_rating 
    if(abs(punt1[4] - punt2[4]) > 0.5)
        distancia=+8; 
    
    //cont_rating
    if(punt1[5]==punt2[5] && punt1[6]==punt2[6] && punt1[7]==punt2[7] && punt1[8]==punt2[8])
        igual = true;
    if(!igual)
        distancia=+7.5;
    igual=false;

    //genre
    if(punt1[9]==punt2[9] && punt1[10]==punt2[10] && punt1[11]==punt2[11] && punt1[12]==punt2[12] && punt1[13]==punt2[13] && punt1[14]==punt2[14] && punt1[15]==punt2[15] && punt1[16]==punt2[16] && punt1[17]==punt2[17] && punt1[18]==punt2[18] && punt1[19]==punt2[19] && punt1[20]==punt2[20] && punt1[21]==punt2[21] && punt1[22]==punt2[22] && punt1[23]==punt2[23] && punt1[24]==punt2[24] && punt1[25]==punt2[25] && punt1[26]==punt2[26] && punt1[27]==punt2[27] && punt1[28]==punt2[28] && punt1[29]==punt2[29] && punt1[30]==punt2[30] && punt1[31]==punt2[31])
        igual = true;
    if(!igual)
        distancia=+11;

    //sup_device.num
    if(abs(punt1[32] - punt2[32]) > 5)
        distancia=+4.5; 
    //ipadSc_urls.num
    if(abs(punt1[33] - punt2[33]) > 1)
        distancia=+3; 
    //lang.num
    if(abs(punt1[34] - punt2[34]) > 5)
        distancia=+5;
    //vpp_lic
    if(punt1[35] != punt2[35])
        distancia=+7;

    return distancia;
}

double distanciaDimension(vector<double> punt1, vector<double> punt2, unsigned dimension){
    if(dimension == 0){
        return abs(punt1[0] - punt2[0]);
    }else if (dimension == 1){
        return abs(punt1[1] - punt2[1]);
    }else if (dimension == 2){
        return abs(punt1[2] - punt2[2]);
    }else if (dimension == 3){
        return abs(punt1[3] - punt2[3]);
    }else if (dimension == 4){
        return abs(punt1[4] - punt2[4]);
    }else if (dimension == 5 || dimension == 6 || dimension == 7 || dimension == 8){
        if(punt1[5]==punt2[5] && punt1[6]==punt2[6] && punt1[7]==punt2[7] && punt1[8]==punt2[8])
            return 0;
        else
            return 7.5;
    }else if (dimension == 9 || dimension == 10 || dimension == 11 || dimension == 12 || dimension == 13 ||dimension == 14 || dimension == 15 || dimension == 16 || dimension == 17||dimension == 18 || dimension == 19 || dimension == 20 || dimension == 21||dimension == 22 || dimension == 23 || dimension == 24 || dimension == 25 || dimension == 26 || dimension == 27 || dimension == 28 || dimension == 29|| dimension == 30 || dimension == 31){
        if(punt1[9]==punt2[9] && punt1[10]==punt2[10] && punt1[11]==punt2[11] && punt1[12]==punt2[12] && punt1[13]==punt2[13] && punt1[14]==punt2[14] && punt1[15]==punt2[15] && punt1[16]==punt2[16] && punt1[17]==punt2[17] && punt1[18]==punt2[18] && punt1[19]==punt2[19] && punt1[20]==punt2[20] && punt1[21]==punt2[21] && punt1[22]==punt2[22] && punt1[23]==punt2[23] && punt1[24]==punt2[24] && punt1[25]==punt2[25] && punt1[26]==punt2[26] && punt1[27]==punt2[27] && punt1[28]==punt2[28] && punt1[29]==punt2[29] && punt1[30]==punt2[30] && punt1[31]==punt2[31])
            return 0;
        else
            return 11;
    }else if (dimension == 32){
        return abs(punt1[32] - punt2[32]);
    }else if (dimension == 33){
        return abs(punt1[33] - punt2[33]);
    }else if (dimension == 34){
        return abs(punt1[34] - punt2[34]);
    }else if (dimension == 35){
        return abs(punt1[35] - punt2[35]);        
    }
}

void leerData(string archivo, kd_node* root)
{
    string s;
    int i=0, k=0;
    ifstream f( archivo );
    getline(f, s);
    while(getline(f, s))
    {
        vector<string> data;
        vector<double> comparables;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '"'){
                s.erase(i, 1);
            }
        }        
        // stringstream class check1
        stringstream check1(s);
        
        string intermediate;
        
        // Tokenizing w.r.t. space ' '
        getline(check1, intermediate, ',');
        while(getline(check1, intermediate, ','))
        {
            data.push_back(intermediate);
        }
        
        cout << data[2] << " " << data[4] << " "  << data[5] << " " << data[6] << " " << data[7] << " " << endl;

        k=0;
        for(i=0; i<16; i++)
        {
            if(i==2 || i==4 || i==5 || i==6|| i==7 || i==8|| i==10|| i==11 || i==12 || i==13 || i==14)
            {
                if(i==10)
                {
                   if(data[i].compare("4+")){
                       comparables.push_back(1);
                       comparables.push_back(0);
                       comparables.push_back(0);
                       comparables.push_back(0);
                   }else if(data[i].compare("9+")){
                       comparables.push_back(0);
                       comparables.push_back(1);
                       comparables.push_back(0);
                       comparables.push_back(0);
                   }else if(data[i].compare("12+")){
                       comparables.push_back(0);
                       comparables.push_back(0);
                       comparables.push_back(1);
                       comparables.push_back(0);
                   }else if(data[i].compare("17+")){
                       comparables.push_back(0);
                       comparables.push_back(0);
                       comparables.push_back(0);
                       comparables.push_back(1);
                   }       
                }else if(i==11)
                {
                    if(data[i].compare("Book"))
                    {
                        for(int j=0; j<23;j++)
                        {
                            if(j=0)
                                comparables.push_back(1);
                        comparables.push_back(0);
                        }    
                    }else if(data[i].compare("Business")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=1)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }    
                    }else if(data[i].compare("Catalogs")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=2)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }    
                    }else if(data[i].compare("Education")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=3)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Entertaiment")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=4)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Finance")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=5)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Food & Drink")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=6)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Games")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=7)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Health & Fitness")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=8)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Lifestyle")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=9)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Medical")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=10)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Music")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=11)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Navigation")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=12)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("News")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=13)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Photo & Video")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=14)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Productivity")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=15)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Reference")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=16)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Shopping")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=17)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Social Networking")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=18)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Sports")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=19)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Travel")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=20)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Utilities")){
                            for(int j=0; j<23;j++)
                        {
                            if(j=21)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }else if(data[i].compare("Weather")){
                        for(int j=0; j<23;j++)
                        {
                            if(j=22)
                                comparables.push_back(1);
                            comparables.push_back(0);
                        }  
                    }
                }else
                {
                    comparables.push_back((double)stod(data[i]));
                } 
                
            }
        }
        
        cout << comparables[1] << endl;
        
        root = insert(root, comparables, data);
        comparables.clear();
        data.clear();
    }   
    f.close();
}

kd_node encontrarDatoID(kd_node* root, string filtro){
    stack<kd_node> S;
    kd_node actual;
    kd_node data;
    S.push(*root);
    while(S.size() > 0){
        actual = S.top();
        S.pop();
        
        if(filtro.compare(actual.getData()[1]) == 0){
            data = actual;
            return data;
        }

        if(actual.getLeft() != NULL){
            S.push(*actual.getLeft());
        }
        if(actual.getRight() != NULL){
            S.push(*actual.getRight());
        }
    }
    return data;
}

vector<kd_node> encontrarNCercanas(int N, kd_node* root, string filtro){
    stack<kd_node> S;
    kd_node node, buscado;
    buscado = encontrarDatoID(root, filtro);
    vector<kd_node> datas;
    S.push(*root);
    int k = root->getPoint().size();
    while(S.size() > 0){
        node = S.top();
        S.pop();
        unsigned dim = node.getDepth() % k;
        
        //tratar de insertar node.p en N
        if(datas.empty()){
            datas.push_back(node);
        }
        else{
            double distanciaActual = distancia(buscado.getPoint(), node.getPoint());
            for(int i=1; i<=datas.size(); i++){
                if(distanciaActual < distancia(buscado.getPoint(), datas[i-1].getPoint())){
                    datas.insert(datas.begin() + (i-1), node);
                    break;
                }
            }
            if(datas.size() > N){
                datas.pop_back();
            }
        }

        if (buscado.getPoint()[dim] < node.getPoint()[dim]){
            int distanciaMitad = distanciaDimension(buscado.getPoint(), node.getPoint(), dim);
            if (distanciaMitad < distancia(buscado.getPoint(), datas[N].getPoint())){
                S.push(*node.getRight());
            } 
            S.push(*node.getLeft()); //sale primero
        }
        else{
            int distanciaMitad = distanciaDimension(buscado.getPoint(), node.getPoint(), dim);
            if (distanciaMitad < distancia(buscado.getPoint(), datas[N].getPoint())){
                S.push(*node.getLeft()); 
            }
            S.push(*node.getRight()); //sale primero
        }
    }
    return datas;
}

// Driver program to test above functions
int main()
{
    kd_node root;
    //KDTree tree(*root);

    vector<string> datas2[] = {{"281656475","PAC-MAN Premium","100788224","USD","3.99","21292","26","4","4.5","6.3.5","4+","Games","38","5","10","1"}, {"283619399","Shanghai Mahjong","10485713","USD","0.99","8253","5516","4","4","1.8","4+","Games","47","5","1","1"}}; 
    vector<double> points2[] = {{100788224,3.99,21292,26,4,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,5,10,1}, {10485713,0.99,8253,5516,4,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,47,5,1,1}};  

    leerData("Desafio3.csv", &root);
    
    //leerData("Desafio3.csv");
    printData(encontrarDatoID(&root, "283619399"));
    printData(encontrarDatoID(&root, "281656475"));

    return 0;
}
