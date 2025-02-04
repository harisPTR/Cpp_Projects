#include <iostream>

class Gun{
    private:
        std::string name;
        int maxammo;
        int magammo;

    public:

    //constructs gun with name,capacity and a loaded mag
    Gun(std::string n,int maxa){
        name = n;
        maxammo = maxa;
        magammo = maxa;
    }

    std::string Getname(){
        return name;
    }

    int Getmagammo(){
        return magammo;
    }

    //checks if mag has bullets,fires
    void Fire(){
        if(magammo > 0){
            std::cout<<"pew"<<std::endl;
            magammo--;
        }
        else{
            std::cout<<"clack,out of ammo"<<std::endl;
        }
    }

    //reloads the mag
    void Reload(){
        std::cout<<"Reloading!!"<<std::endl;
        magammo = maxammo;
    }
};

//changes the selected gun from main
void Selectgun(int& sel,Gun g[],int size){

    //displays your options
    std::cout<<"Please select your gun:\n";
    for(int i=0;i < size;i++){
        std::cout << i << ": " + g[i].Getname()<<'\n';
    }

    //checks for valid input
    bool ans = true;
    do{
    std::cin >> sel;
    if(sel >= 0 && sel < size){
        ans = false;
    }
    }while(ans);
}

int main(){

    int selectedgun;
    Gun guns[]{
           Gun("Revolver",6),
           Gun("M1911",20)
    };

    //find how many guns we got and runs the function
    int sizeofguns = sizeof(guns) / sizeof(guns[0]);
    Selectgun(selectedgun,guns,sizeofguns);

    bool exit = true;
    int ans;
    std::cout << "You can fire,reload,see how much ammo is left by typing:\n"
    << "0:Exit\n1:Fire\n2:reload\n3:check\n4:change gun" <<std::endl;
    do{
        std::cin>>ans;
        switch(ans){
            case 0:
                exit = false;
                break;
            case 1:
                guns[selectedgun].Fire();
                break;
            case 2:
                guns[selectedgun].Reload();
                break;
            case 3:
                std::cout << guns[selectedgun].Getmagammo() << std::endl;
                break;
            case 4:
                Selectgun(selectedgun,guns,sizeofguns);
                std::cout << "You can fire,reload,see how much ammo is left by typing:\n"
                << "0:Exit\n1:Fire\n2:reload\n3:check\n4:change gun" <<std::endl;
                break;
        }
    }while(exit);
    return 0;
}