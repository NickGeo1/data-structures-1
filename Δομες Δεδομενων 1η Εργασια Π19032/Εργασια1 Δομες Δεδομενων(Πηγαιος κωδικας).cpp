#include <iostream>

#include <ctime>
#include <cstdlib>

#include <sstream>



using namespace std;


//���������� ��������-������


template<class T>

//����� template �� �� ����� ChainNode � ����� ��������:
class ChainNode {
	
	public:

		int vel; //��� ��������� ��� ��� �������� �� ���� ����� ���� ������
		string ispatient; //��� ��������� ��� �� �� ���� ������� ����� ������� � ���(true or false)
		int positionx;
		int positiony;//���������� ��� ��� ������������� �� ���� ����� ���� ������
		T time; //��������� ��� ��� ��� ���������� ��� ������ �� ��� ������, � ����� ������������ ����� ������� ��� 
		ChainNode<T> *nextpos; //������ ��� ������� ���� ������� ����� ��� ������
};







template<class T>

//����� template �� �� ����� Chain � ����� �������� ��� ����������� ��� ��������
class Chain {

	public:

		ChainNode<T> *first; //������� ������ ������ first

//���������� �� ������� ��� �������� ���� ������
		
		int Length() const{ 
			
			ChainNode<T> *current = first; //���������� current ��� ����� ����� ��� ������
			int l = 0; //������� �� ������� 0
			
			while (current) { //��� � current ��� ����� null 
				l++;//������ �� ������� ���� 1
				current = current->nextpos; //������� ���� ������� �����
			}
		
			return l; //��������� �� ������� (len)

		}	

//����� ��� � �� ���� time ��� j-����� ������ ���� ������ ��� ��� ����������
		
		int GetNodeTime(int j) const{

			ChainNode<T> *current = first; //������� current ��� ����� �����
			int index = 1; // �� index ���� ������� ��� ����� ���� ����� �����������(������ ���� 1�)
			int x;//��������� x ���� ����� �� ������������� �� time ��� j-����� ������

			if (j==1){ //�� ������� �� time ��� ������ ������ ���� ������� ��� �� ����� ���� index = 1
				x = current->time; //���� ��� � �� time ��� current ��� �� ���� �� ���� ����� � ������ ������
				return x;//��������� �� � 
			}

			//�� ������� �� time ���� ����� ������ ���� ����������� ���� �� ����������

			while (index < j && current) {//��� ������� ���� ��� ����� ��� ������� ��� � current ��� ����� null
				current = current->nextpos;//���� ���� ������� ����� ��� current 
				x = current->time;//������� �� ���� time ��� �������� ������ ��� �
				index++;//��������� �� index ���� 1 ��� �� ������� �� ���� ����� �����������
			}

			return x;//���� �������� ��� ����� ��� ��� ���������� ������������ �� � (�� time ��� ��� ����������)

		}
		
//���� � ��������� �������� ��� ����� �� �� �������� ��� ������ ��� ��������� (� ����� ���������� ����� �� ������� ������ ��� ������� �� �������� ��� ���)

		Chain<T>& Insert(int k, const T& t, const int& v, const string& isp, const int& posx, const int& posy){     

			ChainNode<T> *prev = first;//������� prev ��� ����� ����� 

			for (int index = 1; index < k && prev; index++){ //����������� ��� prev ���� k-���� ����� � ������ ����� ����� ��� ��� ����� �� ������� ���� ������� ���
			//��� ��������� �����
				prev = prev->nextpos;
			}

			ChainNode<T> *n = new ChainNode<T>; //������������ ��� ��� ����� n
	
			n->time=t; 
			n->vel=v; 
			n->ispatient=isp; 
			n->positionx=posx; 
			n->positiony=posy;//������� �� ����� ���� ��� ����������� ����� ��� ����������
	
			if (k!=0) {//�� �� k ��� ����� ����� �������� ��� �� �������� ��������� �����
				n->nextpos = prev->nextpos;//���� ��� ������� ��� ���������� (n) �� ����� � �������� ��� prev (���� ����� ���� �������)
				prev->nextpos = n;//���� ��� ������� ��� prev �� ����� � n (����� ���� ���� ���� � n ��������� ���� p (k-���� �����) ��� �� ����� ��� ���� ���� ��� p) 
			}
			else {//A� �� k ����� �����
				n->nextpos = first; //� �������� ��� n ������� o first 
				first = n;//���� ����� ��� first �� ����� � n
			}
		
		}	




		void Output(int d){//� ��������� ���� ������� ����� ���� ������� ���������� ��� ��� ����� ��� ����� ��� �� ��� ����

			ChainNode<T> *tmp;//������ ���� ����� tmp

			tmp=first;//���� ��� tmp �� ����� � first (� first ��� object chain �� �� ����� �� �������� �� ���������)
			
			for (int startnode=1; startnode<10*(d-1)+1; startnode++){
				tmp=tmp->nextpos;
			}//� tmp ������ ���� ����� ����� ��� ������ ��� ������� ��� ������

			while(tmp != NULL){//��� � tmp ��� ����� null ������ ��� �� �������� ��� ��� ������� ���� �������
	
				cout <<"\nTime: "<< tmp->time<<endl;
				cout <<"Velocity to this position: "<< tmp->vel<<endl;
				cout <<"Is patient: "<< tmp->ispatient<<endl;
				cout <<"Position: "<<"(" << tmp->positionx << ","<<tmp->positiony<<")\n\n"<<endl;

				tmp = tmp->nextpos;
			}

		}


};

//#######################################################################################################################################




//��� ��������� �� ����������� POSSIBLE_COVID_19_INFECTION, FIND_CROWDED_PLACES, REPAIR ��� SUMMARIZE_TRAJECTORY, �� objects �������, ���� ������ 
//��� ������� ����� ����������� ��� ������ ��� �� ��������������� ��� ������� �����������


string returnbool(bool b){ //��������� ��� ���������� �� string true � false (��� ������ 1 � 0 ����������)
	if (b){
		return "TRUE";
	}
	return "FALSE";
};



int randomnum;
int random_x;
int random_y;
int random_v;//���������� ��� �� ������������� �� �������������, � �������� ��� ���� ������� ������� ��� �� 0 ����� �� 4

Chain<int> U1; 
Chain<int> U2;
Chain<int> U3;
Chain<int> U4;
Chain<int> U5;
Chain<int> U6;
Chain<int> U7;
Chain<int> U8;
Chain<int> U9;
Chain<int> U10;
Chain<int> U11;
Chain<int> U12;
Chain<int> U13;
Chain<int> U14;//���������� ��� objects �������

Chain<int> LU1; 
Chain<int> LU2;
Chain<int> LU3;
Chain<int> LU4;
Chain<int> LU5;
Chain<int> LU6;
Chain<int> LU7;
Chain<int> LU8;
Chain<int> LU9;
Chain<int> LU10;
Chain<int> LU11;
Chain<int> LU12;
Chain<int> LU13;
Chain<int> LU14;//���������� ��� ���������� objects ������� �� ����� �� ��������������� ��� �� ��������� SUMMARIZE_TRAJECTORY

Chain<int> ch[14]={U1,U2,U3,U4,U5,U6,U7,U8,U9,U10,U11,U12,U13,U14}; 
Chain<int> ch2[14]={LU1,LU2,LU3,LU4,LU5,LU6,LU7,LU8,LU9,LU10,LU11,LU12,LU13,LU14};//�������� ���� ������� �� ��� array

int Patlist[10];//����� ���� ����� �� ������� ���� �������� (�� i) ��� ������� ��� ������ (�� �������������� ���� ��������� POSSIBLE_COVID_19_INFECTION)
int listsize = 0;//������ �� ��������� ��������� ��� �����

bool searchi(int list[],int i){ //���� � ��������� ����� ��� �� ������ ������ ������������ ������ ���� ������ ��� ����� �� �������.
//�� ������� ���������� true ������ false
	
	for(int j=0; j<=listsize-1; j++){
		if (list[j] == i){
			return true;
		}
	}
	return false;	
}

addnodes(int s,int d,bool b,int i){ //���� � ��������� ���������� ������� ��� ���� �������, �� ������ ��������� ��� �����������: �������������,
//�������� (������� ���� ����), ������������ ���������� ��� ����� ���� ��� ������ ��� ������ ��� �� � ������� ����� ������� � ���(TRUE � FALSE �����������).
	
	if (s==0 && d==1){ //�� ������� ���� ���� ��� ������ ����� ���� �������� 0 ������ ��� ������ (��� 3-6)
		random_v = 0;
	} else{ 
		random_v = (rand() % 4) + 3;
	}
	
	random_x =  (rand() % 11);//���� ������� ������������� (� ��� � ��� 0-10) 
	random_y =  (rand() % 11);
	int N = ch[i].Length();
	ch[i].Insert(N, s + 300*(d-1), random_v, returnbool(b), random_x, random_y); //���������� ���� ������ �� �� �������� ��������
	//��� ��� i-���� ������(���� ���� � �������� ������ ����������� ������ ���� ��� �������)
}






//REPAIR



REPAIR (int d,int i){ 
	
	//��� ��� �������� ���� ����� �����
	
	int L = ch[i].Length();//������� L �� ������� ��� i-����� �������� ��� ������
	
	if (ch[i].first->time !=0){//�� � ������ ������ ��� ���� time=0,���� ��� ����� � ������ ��� ������ ������������
		
		random_x =  (rand() % 11);
		random_y =  (rand() % 11);//������� ������� �������������
		
		if (i==0 || i<=6){//�� � ������� ����� ��� ��� 1� ����� ��� ��� 7�(������) ���� �������� �� ����� ��� ������ ��� ����� ����� �� time=vel=ispatient=false 
		//��� � ��� � ��� ������� �������������
			ch[i].Insert(0, 0, 0, returnbool(0), random_x, random_y);
			L+=1;//������ �� ������� ��� ��������
		}else{
			ch[i].Insert(0, 0, 0, returnbool(1), random_x, random_y);//������ ���� ��� ���� ispatient=true ����� �� ��������� ������� ����� ��������
			L+=1;//������ �� ������� ��� ��������
		}
				
	}
	
	
	//��� ��� �������� ���� ��������� �����
	
	ChainNode<int> *current = ch[i].first; //������������ ���� ��� ����� ��� ������� current = first
	
	while(current->nextpos){ //��� � current ���� �������
		current=current->nextpos; //������� ���� ������� ����� (���� current ��� ������� �����)
	}
	
	int lasttime = current->time;//������� lasttime �� time ��� ���������� ������
	if ((lasttime+30)%300!=0){ //�� � lasttime ��� ����� 270,570,870,...,2970 (����� ����� �� ���������� ���������� time ���� ����� � ���������� ����)
	//�� �� time=600 ���� d=3			
		random_x =  (rand() % 11);
		random_y =  (rand() % 11);
		random_v = (rand() % 4) + 3;//������� ������ � � ��� ��������
			
		if (i==0 || i<=6){
			ch[i].Insert(L, 270+(d-1)*300, random_v, returnbool(0), random_x, random_y);
			L+=1;//������ �� ������� ��� ��������
		}else{																			//���� ��� ��������� ����� �� ��������� time ��� ����������� �����
			ch[i].Insert(L, 270+(d-1)*300, random_v, returnbool(1), random_x, random_y); //(��� ������� ��� ��������)
			L+=1;//������ �� ������� ��� ��������
		}
			
	}
	
	
	//��� ��� �������� �� ��������� �����
	
	bool flag = true;//���� ��� ��������� true
	
	for (int j=10*(d-1)+1; j<L; j++){ //� ��������� �������� ��� ��� ������ ��� ������ ������ ������� ��� ����� ��� ������ ����� ��� ���� �� ����� ��� ��������
										//�� �� d=2 � ��������� ����� ��� j=11 ����� j=19 (���� ���� �������������� 10 ������)
	
		if( d!=1 && (j-1)%10==0 && flag ){//��� ��������� ��� ������ j=11,21,31,...,91 (�� ������ ���� ���� ��� �����) ��� �� flag ����� true
		//������ �� j ���� 1 ��� ���� flag=false(���� �� ������� ����� �� ��� d=1 ������ ��� j=1 ����� 9 ����� ��� ������� � ������� ��� ���� �������
		//��� 2,1 ����� ��� 10,9.��� ������� ���� ��� j=11 ���������� �� 12,11 (������ � ������� 11,10) ����� ����� �������� ���� ���� ������������
		//� 11�� ������ �� ������� ���� �����, �� ���� j=10 ��� �� ������ ���� 11,10.flag=false ��� �� ��� ��������� �� ���� ���� ����� ���� j=11.) 	
			j -=1;
			flag = false;
		}
		
		
		if ((ch[i].GetNodeTime(j+1) - ch[i].GetNodeTime(j))!=30){//�� � ������� ��� time ��� �������� ������ �� ��� ��������� ��� ����� 30
			
			random_v = (rand() % 4) + 3;
			random_x =  (rand() % 11);
			random_y =  (rand() % 11);
			
			
			if (i==0 || i<=6){
				ch[i].Insert(j, ch[i].GetNodeTime(j)+30, random_v, returnbool(0), random_x, random_y);
				L+=1;//������ �� ������� ��� ��������
			}else{																					  //���� ��������� ���� ���� ��� ����� ��� �� time ��� 
				ch[i].Insert(j, ch[i].GetNodeTime(j)+30, random_v, returnbool(1), random_x, random_y);//�� ����� ���� 30 ���������� ��� ��� ���������
				L+=1;//������ �� ������� ��� ��������												 //(��� ������� ��� ��������)
			}
				
		} 
		
		if((j-1)%10==0){
			flag = true;
		} //flag=true ���� ���� j=11,21,31,...,91 ��� ������� ����
	} 		
}







//POSSIBLE_COVID_19_INFECTION



string POSSIBLE_COVID_19_INFECTION(int i,int d){
	ChainNode<int> *hcurrent; //������������ ��� ����� �� ����� hcurrent �� ��� ����� �� ������������� ���� ������� ��� ����� �������
	int hx;
	int hy;//���������� ��� �� ������������ ��� ������������� � ��� y ��� ������
		
	ChainNode<int> *pcurrent;//������������ ��� ����� �� ����� pcurrent �� ��� ����� �� ������������� ���� ������� ��� �������
	int px;
	int py;//���������� ��� �� ������������ ��� ������������� � ��� y ��� ������
	
	ChainNode<int> *checknodes;//������ �� �� ����� checknode �� ��� ����� �� ��������� �� ������ �� ����� ������������� �������
	//��� �� �� ������ ���� ������� ���� ��� ����.
	
	int index; 
	
	int C1=-30; //�������� ��� �� �������� ��� ������ � ������� ����� ��� ������� ���� ������
	int C2=-30; //�������� ��� �� �������� ��� ������ �� ��������� ���� ������ ���� ������ ������ ������

	
	for(int j=7; j<=13; j++){ //�������� ��� ������� ���� ��� ������� (8� ��� 14� �������� ��� array) �� ��� i-���� ������
	
		if (d==1){ //�� ������� ���� ����� ���� ���������� �� ��������
			hcurrent = ch[i].first; //���� ���� ���� ��� ��������� ������� ���� hcurrent ��� ����� ����� ��� i-����� ����� ������
			hx = hcurrent->positionx;
			hy = hcurrent->positiony;//������������ ��� ������������� � ��� y ��� ������ ������ �� 2 ���������� ���� ���� ���� ��� ���������
				
			index = 1; //� ���������� ��������� ��� ������������� ��� i-����� ������ �� ��� ����������� ������������� ��� 
				//j-����� ������ ������ ��� ���� ������� ���� �������
		}
		
		if(d!=1){//�� ��� ������� ���� ����� ���� ���������� �� ��������
				
			index=5+10*(d-2); //� ���������� ��������� ��� i-����� ������ �� ��� ���� j-���� ������ ������ ��� ���� ������� 5,15,25,...,85 ��� ������� ���
			//d=2,3,4,...,10 ����������
				
			hcurrent = ch[i].first;
			 
			for(int k=1; k<index; k++){
				hcurrent=hcurrent->nextpos; //���� ���� ���� ��� ��������� ������� ���� hcurrent ��� ����� ����� ��� i-����� ����� ������
				//��� ��� ����������� ����� �� ������ ��� ��������� ������ ����� (������� �� ���� ��� �� index).
			}
				
		}
			
			
		pcurrent = ch[j].first; //���� ���� ���� ��� ��������� ������� ���� pcurrent ��� ����� ����� ��� j-����� ������
		px = pcurrent->positionx;
		py = pcurrent->positiony;//������������ ��� ������������� � ��� y ��� ������ ������ �� 2 ���������� ���� ���� ���� ��� ���������
			
		for(int k=1; k<index; k++){//�� d=index=1 ���� ��� ����������� ��� pcurrent
			
			pcurrent = pcurrent->nextpos;
			px = pcurrent->positionx;
			py = pcurrent->positiony;//������� �� ���� ��� �� index �������������� ���� ��������� ����� ��� j-����� ������(���� ��� �� hcurrent ��� � pcurrent
			//���������� �� ������������ �������)�� ��� d=4 ����� index=25 ����� � �������� ������ ��� ���� 25��� ������� ��� ������ ��� ��� ������ 
			
		}
			
		int validcheckcounter = 1;  //�� ����� ��� ������� ��������� �� �������� 6 �������� ������ ���������� ��� ����� ��� �������
			
		while(true){ //� ���������� ����� ��� ���� ��� �� �������� ���� i-���� ����� ������ �� ���� j-���� ������ ����� � ��������:
			
			//������ �������� ��� ���� ������� ������� ��� ������ ��� ��� ������.��� ����� ���� ����� ����� ��� ������,������ ��� ������������� ���
			//������ ������ ��� ����� ���� ��� ��� ������������� ����� 6 ��������� ������� ��� ����� (�������� 180") ��� �� �� ��� � ������ ������� ������
			//��� 60" ���� ������ ��� ������ ������ ��� ������ (������ 2 ������) ��� ���� ���� ������ (�������� 180").�� � ������� ��������� ��� ������ 
			//���� ������ ��� ���� ���� ������, � ��������� ��������� TRUE ��� �����, ������ FALSE.��� �������� ������ ���� �� ���������� ��� ��� ���� ������
			//��� ������, ���� �� �������� ������� ���� 2��� ����.���� ����� �� ������� ��� ��� ����� 6 ��������� ��� ���� ����,���� � ���������� ��������� 
			//��� ��� ���� ������,�� ����������� ������(���������� ���� ��� ���� ������� ���� �������) ����� �� ������ ����� ���� ������� �� ����� ��� 
			//������ ������ �� ����.��� ��� ���� ������� ��� ��������� �� ������ ��� ����������� ����
			//��� ��� ������, ���� ������ ��� ������� ���� �� �������� ��� ���������� �����.��� ���� � ���������� ��������������� ��� ����� ���� 7 �������
			//���� ��� ���� ��� ��� ���� ��� 10 �����.
					
			checknodes = hcurrent; //� ������� ��� �� �� �������� 6 ���������� �������������� ������ �������� ��� ��� ����� hcurrent
					
			while(checknodes->nextpos){ //��� � checknodes ���� ������� �����
						
				checknodes=checknodes->nextpos; //���� ��� checknodes ���� �������
				validcheckcounter+=1; //������ ��� ������� ���� 1

				if(validcheckcounter==7){ //�� � �������� ����� 7 ���� �������� ��� �������� 6 �������������� ������ ��� ������ �� �����
				//������������� ������� ��� �� �� � ������� ������ ������ �� ����, �� �������� ��� hcurrent. 
					break ;	
				}
					
			}
				
			if(index<95){//�� ��������� ������ ��� ���� ������ ����� 100 (��� ���� ��� �����) �������� �� �������� ���� 95� ���� ������ �������� 
			//��� �������� 6 �������������� ���� ����� ������ �� ������� � ������� �� �� hcurrent ��� pcurrent ����� �������� ��� 95� ����� ��� ��� 98� 
			//����� ����� ������� �� ��������� ��� ���� 95-98.
				
				if(validcheckcounter!=7){ //�� �� index<95 ��� � �������� ��� ����� 7 ���� �������� ��� ��� ������ �� ����� ������������� �������
				//������ �� ���� ��� �� ����� ��� �������
					break;
				}
			}
					
									    
			while(C2!=180){ //��� � �������� C2 ��� ����� 180(������ � ������ ��� j-����� ������ ������ �� �������� ������� ������)
		
				if((px==hx && py==hy)||(px+2==hx && py==hy)||(px-2==hx && py==hy)||(px==hx && py+2==hy)||(px==hx && py-2==hy)||
				(px+1==hx && py+1==hy)||(px-1==hx && py-1==hy)||(px-1==hx && py+1==hy)||(px+1==hx && py-1==hy)||(px+1==hx && py==hy)||
				(px-1==hx && py==hy)||(px==hx && py+1==hy)||(px==hx && py-1==hy)){ //�� � i-����� ������� ��������� �� "������ 2 ������" ��� ��� j-���� ������
						
					C1+=30; //��� ����� ���� � �������� ������ ��� 0 ��� ��������� ���� 30 �� � ������� ������ ���� ��� ������� 30" ���� "������" ��� ������
				
				}else{
					
					C1=-30;//�� � i-����� ������� �� ��������� �� "������ 2 ������" ��� ��� j-���� ������ ���� ���� ��� ������� c2 = -30
				}
						
				C2+=30; //���������� �� �������� ��� ����� ������ � ������ ��� j-����� ������
		
				if(C2!=180 && C1==60){ //�� ��� ���� ����� � �������� ��� ������� ��� � ������� ��������� ����� ��� ������� ��� j-����� ������ 
				//��� 60" � i-����� ������� ����� ������� �������
							
					Patlist[listsize]=i;//���� ��� ����� ��� ������ ��� i-����� ������ ��� ������.
					listsize+=1;//������ �� ������ ��� �� ��������� ��������� ���						
					return "TRUE";//��������� true
				}
		
				if(C2!=180){ //��� ��� ���� ����� � �������� ��� ������� ������ ��� �������� ������������� ��� i-���� ������ ����� �� �������� �� ����� ��� �������������
				//�� ������ ��� ����� � ������
					if(!(hcurrent->nextpos)){ //�� ����������� ��� ��� ������� �������� ������ ��� ����� ����� ������ � ������ 
					//(��� ��������� ��� ������ ������ ���� 100���� ����� ��� �����) �������� �� ����������
						break;
					}
					hcurrent=hcurrent->nextpos;
					hx = hcurrent->positionx;
					hy = hcurrent->positiony;
				}
				
			}
			
			pcurrent=pcurrent->nextpos; //��� ���� ������� ����� ��� ������		
			px = pcurrent->positionx;
			py = pcurrent->positiony;//��������� ��� ������������� ���
					
			hcurrent=ch[i].first;//��� ���� ����� ����� ��� �����
		
			for(int i=1; i<=index; i++){
					
				hcurrent=hcurrent->nextpos; 												
			}//��� �������� ���� ������� ����� ��� ����� ����� �� ����� ���� ���������� ��� ������.�� �� ��� ������ ����� � 3�� (index = 2) ����
			//������� ��� ������ ��� ��� ������ ��� ����� ��� �� ����� ���� 3�.
			hx = hcurrent->positionx;
			hy = hcurrent->positiony;//��������� ��� ������������� ������� ��� ������ ��� �����
					
			C1=-30;
			C2=-30;//���� ���� ���� �������� -30
			index+=1; //������ �� index ��� �� ������������ ����� ��� ������� ���� � �������� ����������				
			validcheckcounter = 1;
					
			if (index==99){ //�� ����������� ���� ����� 99 � ������� ��� ����� ������ �� ������� ����� ������������ false
				return "FALSE";
			}
		}
	}	
		
	return "FALSE"; //�� ���� �� �������� ���� ������ �� ��� i-���� ������ ��� ������ ��� ����� ��� ���� ��� ������ � ������� ������������ false
}






//SUMMARIZE_TRAJECTORY




SUMMARIZE_TRAJECTORY(int d,int i,int sumday){
	
	ChainNode<int> *specificdnd = ch2[i].first; //������� specificdnd ��� ����� ����� ��� ���������� i-����� ������
		
	ChainNode<int> *tmpnd;//���� tmpnd �� ������������ ��������� ��� ����� ��� �� ������� �� �����������
	ChainNode<int> *prevspecificdnd; //�� ����� �� ������������ ����� ��� ����������� ��� ����� ��� ����� ������ ��� �� ����������
	bool flag = true; 
	int dfx;
	int dfy;//���������� ���� ������ ������������ ��� ������������� ��� ������ ������
	int dsx;
	int dsy;//���������� ���� ������ ������������ ��� ������������� ��� �������� ������
	//���� ���� ��������� ��� ������� �� ���� ��� ����� �����.������� �� ���� ����� ��� ��������� �� ����� ����� ������� 3 ������ ��� ��� ����� 		
		
	while((specificdnd->time)!=300*(sumday-1)){	//��� �� time ��� specificdnd ��� ����� �� ����� ��� ����������� ����� ������� ���� ������� �����
	//(���� �������� ���� ����� ����� ��� ����������� ����� ����� �� ���������� ����� ����� �������)
		specificdnd=specificdnd->nextpos;
	}
		
	for (int index=1; index<10; index++){//������� ������� ��� ��� ����� ����� ��� ����������� ����� ����� ��� ��� ��������� ��� ����������� �����
		dfx=specificdnd->positionx;
		dfy=specificdnd->positiony;//���� ��� dfx ��� dfy ��� ������������� � ��� y ���������� ��� ���� � specificdnd ������ �� ������
		//(������������ ��� ������������� ��� ������)
		prevspecificdnd=specificdnd;//������� ��� prevspecificdnd �� ����� ��� ���� ������ �� ��� specificdnd ���� ������ ���� ��������� while
		//(������� ���� ����� ��� ������)

		while(true){//�� ������� ��� ����� �����, ��� � �������� ����� ����� ��� ������� ��� ������ ������� ��� �������� �� �������� ���� ����������.
		//���� ����� ������� ��� ��� ����� ���� ������, ���� ��� �� while ��� ������� ����� ����� ��� ��� ���� ���� ������.
		
			if(flag==true){//�� �� flag ����� true ������� ���� ������� ����� 
				specificdnd=specificdnd->nextpos;
			}

			dsx=specificdnd->positionx;
			dsy=specificdnd->positiony;//������������ ��� ������������� ��� �������� ������

			if((dfx==dsx && dfy==dsy)||(dfx+2==dsx && dfy==dsy)||(dfx-2==dsx && dfy==dsy)||(dfx==dsx && dfy+2==dsy)||(dfx==dsx && dfy-2==dsy)||
			(dfx+1==dsx && dfy+1==dsy)||(dfx-1==dsx && dfy-1==dsy)||(dfx-1==dsx && dfy+1==dsy)||(dfx+1==dsx && dfy-1==dsy)||(dfx+1==dsx && dfy==dsy)||
			(dfx-1==dsx && dfy==dsy)||(dfx==dsx && dfy+1==dsy)||(dfx==dsx && dfy-1==dsy)||(dfx+3==dsx && dfy==dsy)||(dfx-3==dsx && dfy==dsy)||
			(dfx==dsx && dfy+3==dsy)||(dfx==dsx && dfy-3==dsy)||(dfx-2==dsx && dfy-2==dsy)||(dfx+2==dsx && dfy+2==dsy)||(dfx+2==dsx && dfy-2==dsy)||
			(dfx-2==dsx && dfy+2==dsy)||(dfx+2==dsx && dfy-1==dsy)||(dfx+2==dsx && dfy+1==dsy)||(dfx-2==dsx && dfy+1==dsy)||(dfx-2==dsx && dfy-1==dsy)||
			(dfx+1==dsx && dfy+2==dsy)||(dfx+1==dsx && dfy-2==dsy)||(dfx-1==dsx && dfy+2==dsy)||(dfx-1==dsx && dfy-2==dsy))
			{//�� �� ������������� ��� �������� ���������� ����� ������� 3 ������ ��� ����� ��� ������	
				tmpnd=specificdnd; //���� ��� ������� temp
				specificdnd=specificdnd->nextpos; //������� ���� ������� �����(��� ���������� 3�. � 3�� �� ������ ��� ���� ���� ���� ��������
				//���� �� �������� ��� ��� ��������)
				prevspecificdnd->nextpos=tmpnd->nextpos;//� �������� ��� 1�� ������� � 3�� (���� � 1�� ��� � 2�� ����� ��� ���� ������� �����)
				index++;//������ �� index ����� ��� ���������� ������� ����
				delete tmpnd;//����� ��� tmpnd (����� � 2��)
				flag=false;	//���� �� flag false ��� �� ��� ��������� ���� ������� ����� ���� �� ��������� �� while (� while ������ ���� ���� �������
				//������� 2�� ������)
				if(index==10){
					break;
				}	
							
			}else{//�� � �������� ��� ����� ����� ��� ������� ��� ������ ���� ���� ��� ��� ���������  
				flag=true;//���� flag = true ���� ���� ���� ��������� ��� while �� ����������� ���� ������� �����
				break;
			}
		}
			
	}
	
}






//FIND_CROWDED_PLACES



int users;//Global ��������� users, ���������� ����� ������� �������� ��� ��������� ������� ��� ���������� ���� (����� ����� ��� ���� main ��� �� 
//������ �� ��� ��������� ���� ������ � FIND_CROWDED_PLACES ��� ����� ����
//������� ��� ���������� ����� �������� ��� ��������� �������)

FIND_CROWDED_PLACES(int d, int i, int timeinterval, int squaredimensions, int squarelowerlefttcornerx, int squarelowerlefttcornery, int minimumstay){
		
	ChainNode<int> *current = ch[i].first;//������� current ��� ����� ����� ��� i-����� ������
	int Cti=-30;//�������� ��� ������� �� �������� ��� ����� ������ � �������
	int Cms=-30;//�������� ��� ������� ���� ��� ������ ���� ������� ��� �������
	if(i==0){//���� ���������� �� �������� ��� ��� ����� ������, ���� users=0 (��� ���� �������� ������� ������� �����)
		users=0;
	}
		
	for(int index=1; index<10*(d-1)+1; index++){
		current=current->nextpos;
	}//� current ������ ���� ����� ����� ��� ����������� ������
		
	int ux = current->positionx;
	int uy = current->positiony;//���������� ��� ������������� ��� ������ ������ ��� ����������� ������ 
	
	while(Cti!=timeinterval){//��� � ������� ����� ����� ������ (���� ��������, ��� ����������� ����� ��� ������� �������� ��� ��� ���������� ��� �� 
	//���������� ��� �������)
			
		Cti+=30; //������ ��� ������� ��������� ��� �������� (��� ����� ���� ������ ��� 0 ���� ����������� ���� ����� �����) 
			
		if(ux>=squarelowerlefttcornerx && ux<=(squaredimensions+squarelowerlefttcornerx) &&
		uy>=squarelowerlefttcornery && uy<=(squaredimensions+squarelowerlefttcornery)){//�� � ������� ��������� ����� ��� ��������				
			Cms+=30;//������ ��� ������� ��� ������� �� �������� �������� ��� ������ ��� ������� (��� ����� ���� ������ ��� 0 
			//���� ����� ��������� ���� �������) 
		}else{				
			Cms=-30;//�� � ������� ��� ��������� ��� ������� ���� ���� Cms=-30;
		}
			
		if(Cms==minimumstay&&Cti!=timeinterval){//�� � ������� ��������� ���� ������� ��� �� �������� ����������� ������� �������� ��� ����������� ����� ���
		//������� �������� ��� ��� ����������, ������ ���� 1 �� ������ ��� ������� ��� ������������ ��� ������� ��� ������� �� ���������� ��� ����� ��� ������
			users++;
			break;
		}
			
		if(Cti!=timeinterval){//�� ��� ���� ����� �� ������� �������� ��� ��� ����������, ������� ���� ������� ����� ��� ���������� ��� ������������� ���
			current=current->nextpos;
			ux = current->positionx;
			uy = current->positiony;
		}
	}
	
}



//�������� ��� ������������



int main(){

	srand(time(NULL));// ��� �� ������������� ������� ������� ���� ���� ���� ���������� ���

	for (int d=1; d<=10; d++){ //���� ���� ��������� 10 ������� ��� ��� ���� ������

		for(int s=0; s<=270; s+=30){ //���� "30 ������������" ��������� ���� ��� ����� ��� ��� ���� ������ ����� �� ����� ��� �����
		                                 

			//���������� 7 ������� ��� 7 ����� �������
		
		
	 		for (int i=0; i<=6; i++){ //�������� ������� ��� ���� ������� 7 ������� (������)
	 
				randomnum =  (rand() % 5); //���������� ������ ������ ��� �� 0-4
			
		
				if (randomnum==2){ //�� � ������� ����� 2, ��� ������������ ������ ������ �� ������ (��� 20% ���������� �� ������ ����) 
					continue;
				}else{
					addnodes(s,d,0,i);
				}		
			}
	
		
	
			for (int i=7; i<=13; i++){ //�������� ������� ��� ���� ���������� 7 ������� (�������)
		
				randomnum =  (rand() % 5);
			
				if (randomnum==2){ 
					continue;
				}else{
					addnodes(s,d,1,i);
				}	
			}
		
		}
	
	
	
	
//��� ����� ��� ���� ����� ����������� �� �����������



		cout<<"\n\n\n   						      DAY "<<d<<"\n\n\n"<<endl;;		
	
		string s;
		//������������ �� ������ 10 ������ ��� ������ ��� ������ ��� �� �������� � �������
		cout<<"TRAJECTORIES FOR ALL 14 USERS HAVE BEEN SUCCESSFULLY CREATED FOR DAY "<<d<<endl;
		while(true){
			
			cout<<"\nPLEASE INSERT THE NUMBER (1-14) OF THE USER YOU WANT TO VIEW IT'S TRAJECTORY.WRITE 'NEXT' IF YOU WANT TO RUN THE REPAIR FUNCTION.";
			cin>>s; //������ ��� ��� ������ �� ����� ��� ������ ��� ������ ��� �� ����� ����� �� ����� � ���������� ��� ������ �� ����
			if (s=="NEXT"){
				break;
			}//�� � ������� ����� �� ���������� ���� ������� ���������� ������ �� ������ "NEXT"
	
			stringstream toint(s);//���������� �� string (��� ����� � ������� ��� ������) �� ������
			int i;
			toint>>i;//��� ��������� ��� � ������� ��� ����� ������ �� ���������� �� 0 ����� i=0.
	
			if(i<1||i>14){//�� � ������� ����� ���������� ������ ��� �������� ���� �������
				cout<<"\nPLEASE INSERT A VALID NUMBER"<<endl;
			}else{
				cout<<"\nTRAJECTORY OF USER "<<i<<" AT DAY "<<d<<" IS:\n"<<endl;
				ch[i-1].Output(d);//�� ����� ����� ������ ���������� � Output ��� �� ����� ��� ������� � ������� �� ���� ������ 
				//(������� ���� ������� ��� ������ ��� ����������� �����)
			}
	
		}






//��������������� �� ������ ��� ������������� ����� ��� ����� ���� ������� (REPAIR)



		for(int i=0; i<=13; i++){
			REPAIR (d, i);//� ��������� ������ �� ������ �� ���� ��� ���� i-���� ������
		}

		cout<<"\nTRAJECTORIES FOR ALL 14 USERS HAVE BEEN SUCCESSFULLY REPAIRED FOR DAY "<<d<<endl;	

		while(true){
			
			cout<<"\nPLEASE INSERT THE NUMBER (1-14) OF THE USER YOU WANT TO VIEW IT'S REPAIRED TRAJECTORY."
			<<"WRITE 'NEXT' IF YOU WANT TO RUN THE POSSIBLE_COVID_19_INFECTION FUNCTION.";
			cin>>s;
			if (s=="NEXT"){
				break;
			}
	
			stringstream toint(s);
			int i;
			toint>>i;//��� ��������� ��� � ������� ����� string �� ���������� �� 0 ����� i=0.
	
			if(i<1||i>14){
				cout<<"\nPLEASE INSERT A VALID NUMBER"<<endl;
			}else{
				cout<<"\nREPAIRED TRAJECTORY OF USER "<<i<<" AT DAY "<<d<<" IS:\n"<<endl;
				ch[i-1].Output(d);		
			}
	
		}





//��������� ��� ������� ���� ��� ������ ������� �� ��� ������� ���� ��� ������� ��� �� ������������ ����(��� ��� ��� ����� �������� ��� ������������, �����
//�� ��������� ��� ��� �����������) (POSSIBLE_COVID_19_INFECTION)



		string z;

		for (int i=0; i<=6; i++){//��� ���� ����� ������
		
			if(searchi(Patlist,i)==true){//�� ���� i-����� ������ ������� ����� ������� ��� ��� ����, ���� ���� ��� ����� ��� ��� ������� ���� ��� ���������� ����
				continue;
			}

			z=POSSIBLE_COVID_19_INFECTION(i, d);//� ��������� ������ �� ������ �� ���� ��� ��� i-���� ������(���� ���� ������) ��� ���������� ��� z ���� ���� �� ������������
			//��� ��� ���� ������

			if (d==1){
				cout<<"\nPOSSIBLE INFECTION OF USER "<<i+1<<" AT DAY 1 "<<z<<endl; //��� ����� ���� �� ��������� ���� �� ������ ��� ��� ���� ����� ������
			}
			else{
				cout<<"\nPOSSIBLE INFECTION OF USER "<<i+1<<" AT DAY "<<d<<" OR NEAR THE END OF THE PREVIOUS DAY: "<<z<<endl;
				//��� ��������� ����� �� ��������� ���� �� ������ ��� ��� ���� ����� ������ 
			}		
	
		}
		
		cout<<"\nUSERS WHO HAVE BEEN POSSIBLE INFECTED UNTIL NOW: ";

		for(int i=0; i<=listsize-1; i++){
			cout<<"U"<<Patlist[i]+1<<" ";
		}
		cout<<"\n"<<endl; //��������� ����� ������� ����� ������� ����� ����

		while (true){
			cout<<"WRITE 'NEXT' IF YOU WANT TO RUN THE SUMMARIZE_TRAJECTORY FUNCTION.";
			cin>>s;
			if (s=="NEXT"){
				break;
			}
		}





//���������� ��� ������ ��� ������� ��� ����� � ����� ������ ��� ������ ������ ��� ������ � ������� ��� �� ������������ ���� (SUMMARIZE_TRAJECTORY)



		int db;
		int sumday;
		bool dontshowtxt=false;
		bool dontshowtxt2=true;//��������� ��� �������� ��� �������� ������� ���������

		if(d==1){//�� ����� ���� ������� � ���������� ���� ������ �� �������� ����� ����� ���� ��� �� ������������ �� ������� � ������
	
			while(!(db>0 && db<10)){//��� � ������� ����� ���������� �������� ������ ��� �������� �� ���������
		
				string sdb;
				cout<<"\nINSERT THE AMOUNT (1-9) OF HOW MANY DAYS BEFORE YOU WANT MAKE THE TRAJECTORY SUMMARIZATION(THIS AMOUNT WILL BE THE SAME FOR THE REST DAYS):";
				cin>>sdb;
		
				stringstream toint2(sdb);//���������� ��� ������ ��� ������ �� int
				toint2>>db;//��� ��������� ��� � ������� ����� string �� ���������� �� 0 ����� db=0.
	
				if(!(db>0 && db<10)){
					cout<<"\nPLEASE INSERT A VALID AMOUNT"<<endl;
				}
			}	
		}

		for (int i=0; i<=13; i++){//���, ������� � ���� ����������: �������������� 14 ��������� ��� �������,��� ����� ������������ �� 10-������ ��� ����������� ����� 
		//���� ���� ��� ���� ������������ ����������� �������. ��� ���� �� ��������� �������������� �� ��������� ��� ������� ���� ����, �� ����� �������������� �� ���� 
		//�� ������ ��� ������, ��� �� ��� ��������� ���� ������� ��� ���������� ������� ��� ����������� �� ���������� ��� ������������ ����������� ��� ������� ����.
 
			ChainNode<int> *fln = ch[i].first; //������� fln ��� ����� ����� ��� i-����� ������

			for(int k=1; k<10*(d-1)+1; k++){//�������� ���� ����� ����� ��� ����������� ������
				fln=fln->nextpos;
			}

			int L2=ch2[i].Length();//������� L2 �� length ��� i-����� ����������
			ch2[i].Insert(L2, fln->time, fln->vel, fln->ispatient, fln->positionx, fln->positiony);//������������ �� ���� �� L2 ��� ����� ����� ��� ����������� �����
			//��� i-���� ��������� ��� ��� ����������� �� �������� ��� ����������� ������ (��� ������ ��� �����) ���������� ������

	
			for(int j=1; j<10; j++){
	
				fln=fln->nextpos;
				L2=ch2[i].Length();
				ch2[i].Insert(L2, fln->time, fln->vel, fln->ispatient, fln->positionx, fln->positiony);

			}//������������ ����� ���� ���������� ������� ��� i-����� ���������� ��� ������ �� ����

			sumday=d-db;//��������� � ����� �������� ��� ���� ��� �� ����� � ������
 
			if(sumday>0){//�� ������ ����,���� ����������� ���� ��������� ���� ��� �� ����� ������ �� ���� ��� ��� ���������� (��� ������ ��� ��� ��������� ���� db)
	
				dontshowtxt2=false;
				SUMMARIZE_TRAJECTORY(d,i,sumday);//�������� � ��������� ��� �� ������������ (�� ����� ������) ��� ������ ��� ������ ��� ������� ��� i-���� ���������	

			}else{
			//������ �������� ���� �� ������
				if(dontshowtxt==false){
					cout<<"\nTHERE IS NOT A DAY THAT HAS A DISTANCE OF "<<db<<" DAY(S) FROM DAY "<<d<<endl;
					dontshowtxt = true;//�� ��������� ��� ���� ���� �� ������ ���� ���������, ���� ��� �� ������������� ��� ������ �� ���� ���� dontshowtxt = true
				}
			}

		}

		if(dontshowtxt2==false){//�� ���� ����� ������ ������� ����� ������� � ���������� ���� ������ �� ��� �� ������������ ��� �������� ���
	
			cout<<"\nTRAJECTORIES FOR ALL 14 USERS HAVE BEEN SUCCESSFULLY SUMMARIZED FOR DAY "<<d<<endl;
	
			while(true){
				
				cout<<"\nPLEASE INSERT THE NUMBER (1-14) OF THE USER YOU WANT TO VIEW IT'S SUMMARIZED TRAJECTORY."
				<<"WRITE 'NEXT' IF YOU WANT TO RUN THE FIND_CROWDED_PLACES FUNCTION.";
				cin>>s;
				if (s=="NEXT"){
					break;
				}
	
				stringstream toint(s);
				int i;
				toint>>i;
	
				if(i<1||i>14){
					cout<<"\nPLEASE INSERT A VALID NUMBER"<<endl;
				}else{
					cout<<"\nSUMMARIZED TRAJECTORY OF USER "<<i<<" AT DAY "<<d<<" IS (DAY "<<sumday<<" HAS BEEN CHANGED):"<<endl;
					ch2[i-1].Output(1);//������� ���� ������� ��� ������ ��� ������� � ������� ��� ��� ����� ���� ����� ��� �� ��������� (��� �� ����� ������ �� ������� ���
					//������� ��� ���� ��� ������������ �����)
				}
	
			}
	
		}





//����� �� ���������� ���� ������ �� ������������ ��� ����������� ������� (����������� ��� ���� ����) ����� ��� �������� ��� ���������� (10x10) ��� �� �������� 
//���� ����� �������� ���� �� ���� ��� ���������� ��� ��� ������� �������� ��� ������ ����� ��� ��� ��� ������� ������� ��� ������ ������ �����.
//� ������� �������� ��� ���������� ������ ��� ��� ���� ��� ������.
//(FIND_CROWDED_PLACES)



		int timeinterval=0;
		int squaredimensions;
		int squarelowerlefttcornerx;
		int squarelowerlefttcornery;
		int minimumstay=0;//���������� ��� �� ������������ �� �������� ��� �� ����� � �������

		while(true){
	
			while(!(timeinterval>0 && timeinterval<=270 && timeinterval%30==0)){//���� ���� ��� �������� ���� �� ������ ��� ������ ����� timeinterval=0
			//����� ��� �������� ���� ���� ����������� ���� ��� �� ������
				cout<<"\nINSERT THE TIMEINTERVAL OF THE SQUARE REGION (MUST BE MULTIPLE OF 30 AND BETWEEN 30-270):";
				string stimeinterval;
				cin>>stimeinterval;//� ������� ����� �� ������� ������� ��� ��� ���������� �� �������� 
	
				stringstream toint(stimeinterval);
				toint>>timeinterval;
				if(!(timeinterval>0 && timeinterval<=270 && timeinterval%30==0)){
					cout<<"\nPLEASE INSERT A VALID TIMEINTERVAL"<<endl;//�� � ������� ���� ����� string � ����� ������ ������������ ����
				}
			}
	
			while(!(minimumstay>0 && minimumstay<=270 && minimumstay%30==0)){//���� ���� ��� �������� ���� �� ������ ��� ������ ����� minimumstay=0
			//����� ��� �������� ���� ���� ����������� ���� ��� �� ������
				cout<<"\nINSERT THE MINIMUM STAY DURATION OF THE SQUARE REGION (MUST BE MULTIPLE OF 30 AND BETWEEN 30-270):";
				string sminimumstay;
				cin>>sminimumstay;//� ������� ����� �� ������� �������� ��� ��� ���������� �� �������� �� ��������� ������� ������� ��� ������� ��� �� ������
	
				stringstream toint(sminimumstay);
				toint>>minimumstay;
				if(!(minimumstay>0 && minimumstay<=270 && minimumstay%30==0)){
					cout<<"\nPLEASE INSERT A VALID MINIMUM STAY DURATION"<<endl;//�� � ������� ���� ����� string � ����� ������ ������������ ����
				}
			}
			
			while(true){
	
				cout<<"\nINSERT THE X POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";
				while(!(cin>>squarelowerlefttcornerx)){//��� �������� ������� � ���� � ��� ���� ��������� ������ ��� �������� ��� ��� ������ (����� �� ����� ������)
					cin.clear(); 
    				cin.ignore(INT_MAX, '\n'); 
    				cout<<"\nPLEASE INSERT A VALID X POSITION"<<endl;
    				cout<<"\nINSERT THE X POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";
				}
				if(squarelowerlefttcornerx>=0&&squarelowerlefttcornerx<10){//�� ����� ������ ��������� �� ����� ���� ��� ����� ������� (0-9 ���� � ���� ��������
				//����� ��� �������� ��� �� �������� ��� ������� �� ��������� ��� ����� ������ ��� 10x10 �������� ���) ��� �� ����� ��� ����� ������� �������� 
				//� ������� ���� ������ �������� ���� � ����
					break;
				}else{
					cout<<"\nPLEASE INSERT A VALID X POSITION"<<endl;
				}		
				
			}
	
			while(true){
	
				cout<<"\nINSERT THE Y POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";//������ ��� �� y
				while(!(cin>>squarelowerlefttcornery)){
					cin.clear(); 
    				cin.ignore(INT_MAX, '\n'); 
    				cout<<"\nPLEASE INSERT A VALID Y POSITION"<<endl;
    				cout<<"\nINSERT THE Y POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";
				}
				if(squarelowerlefttcornery>=0&&squarelowerlefttcornery<10){//��� ��� ������� � ���� �������� ����� ��� �������� ��� �� ����� ��� ���� ������
				//��� 10x10 ��������
					break;
				}else{
					cout<<"\nPLEASE INSERT A VALID Y POSITION"<<endl;
				}			
				
			}		
		
			while(true){//��� ��������� �� ��������� ��� ��� ������
	
				cout<<"\nINSERT THE DIMENSIONS OF THE SQUARE REGION (BETWEEN 1-10):";
				while(!(cin>>squaredimensions)){
					cin.clear(); 
    				cin.ignore(INT_MAX, '\n'); 
    				cout<<"\nPLEASE INSERT VALID DIMENSIONS"<<endl;
    				cout<<"\nINSERT THE DIMENSIONS OF THE SQUARE REGION (BETWEEN 1-10):";
				}
				if(squaredimensions>=1&&squaredimensions<=10){//O� ���������� ������ �� ����� ��� 1x1 ����� ��� 10x10
					break;
				}else{
					cout<<"\nPLEASE INSERT VALID DIMENSIONS"<<endl;
				}		
				
			}		
	
			if((squarelowerlefttcornerx+squaredimensions)<=10 && (squarelowerlefttcornery+squaredimensions)<=10){//��� ����� �� �� �������� ��� ����� � ������� ��� 
			//��� ������� ��� ����� ���������� �� ���� ����� ����� ��� ����� ��� 10x10
				cout<<"\nYOUR SQUARE REGION HAS BEEN CREATED!"<<endl;
				cout<<"\nDIMENSIONS: "<<squaredimensions<<endl;
				cout<<"\nLOWER LEFT X: "<<squarelowerlefttcornerx<<endl;
				cout<<"\nLOWER LEFT Y: "<<squarelowerlefttcornery<<endl;
				break;
			}else{
				cout<<"\nYOUR SQUARE'S DIMENSIONS ARE OUT OF BORDER.PLEASE TRY AGAIN"<<endl;//�� ��� �����, ��������� ���� �,y ��� ����������
			}		
			
		
		}	
	

		for(int i=0; i<=13; i++){
			FIND_CROWDED_PLACES(d, i, timeinterval, squaredimensions, squarelowerlefttcornerx, squarelowerlefttcornery, minimumstay);
		}//������� �� �������� ���� ��� ������ ��� ������� ���� ������� 	

		cout<<"\nUSERS DETECTED WHO STAYED FOR "<<minimumstay<<" SECONDS INTO THE GIVEN SQUARE REGION FOR A PERIOD OF "<<timeinterval<<" SECONDS: "<<users<<"\n"<<endl;
		//��������� �� ������������
	
	}


}

