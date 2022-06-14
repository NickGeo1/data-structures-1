#include <iostream>

#include <ctime>
#include <cstdlib>

#include <sstream>



using namespace std;


//Δημιουργια αλυσιδων-κομβων


template<class T>

//Κλαση template με το ονομα ChainNode η οποια περιεχει:
class ChainNode {
	
	public:

		int vel; //Μια μεταβλητη για την ταχυτητα σε εναν κομβο ενος χρηστη
		string ispatient; //Μια μεταβλητη για το αν ενας χρηστης ειναι ασθενης η οχι(true or false)
		int positionx;
		int positiony;//Μεταβλητες για τις συντεταγμενες σε εναν κομβο ενος χρηστη
		T time; //Μεταβλητη για την ωρα καταγραφης του χρηστη σε ενα σημειο, η οποια καταχωρειται στους κομβους του 
		ChainNode<T> *nextpos; //Δεικτη που δειχνει στον επομενο κομβο του χρηστη
};







template<class T>

//Κλαση template με το ονομα Chain η οποια περιεχει τις λειτουργιες των αλυσιδων
class Chain {

	public:

		ChainNode<T> *first; //Δεικτης πρωτου κομβου first

//Επιστρεφει το μεγεθος της αλυσιδας ενος χρηστη
		
		int Length() const{ 
			
			ChainNode<T> *current = first; //Ονομαζουμε current τον πρωτο κομβο του χρηστη
			int l = 0; //Θετουμε το μεγεθος 0
			
			while (current) { //Οσο ο current δεν ειναι null 
				l++;//αυξησε το μεγεθος κατα 1
				current = current->nextpos; //προχορα στον επομενο κομβο
			}
		
			return l; //επεστρεψε το μεγεθος (len)

		}	

//Θετει στο χ τη τιμη time του j-οστου κομβου ενος χρηστη και την επιστρεφει
		
		int GetNodeTime(int j) const{

			ChainNode<T> *current = first; //Θετουμε current τον πρωτο κομβο
			int index = 1; // το index αυτο δειχνει τον κομβο στον οποιο βρισκομαστε(αρχικα στον 1ο)
			int x;//μεταβλητη x στην οποια θα αποθηκευσουμε τη time του j-οστου κομβου

			if (j==1){ //Αν θελουμε το time του πρωτου κομβου τοτε ειμαστε ηδη σε αυτον αφου index = 1
				x = current->time; //θεσε στο χ το time του current που σε αυτη τη φαση ειναι ο πρωτος κομβος
				return x;//επεστρεψε το χ 
			}

			//Αν θελουμε το time ενος αλλου κομβου τοτε ακολουθουμε αυτη τη διαδικασια

			while (index < j && current) {//Οσο ειμαστε πριν τον κομβο που θελουμε και ο current δεν ειναι null
				current = current->nextpos;//παμε στον επομενο κομβο του current 
				x = current->time;//θετουμε τη τιμη time του επομενου κομβου στο χ
				index++;//αυξανουμε το index κατα 1 για να ξερουμε σε ποιο κομβο βρισκομαστε
			}

			return x;//οταν φτασουμε στο κομβο που μας ενδιαφερει επιστρεφουμε το χ (το time που μας ενδιαφερει)

		}
		
//Αυτη η συναρτηση φτιαχνει νεο κομβο με τα στοιχεια που περνει σαν παραμετρο (η πρωτη παραμετρος ειναι σε ποιανου κομβου τον επομενο θα προσθεσω τον νεο)

		Chain<T>& Insert(int k, const T& t, const int& v, const string& isp, const int& posx, const int& posy){     

			ChainNode<T> *prev = first;//Θετουμε prev τον πρωτο κομβο 

			for (int index = 1; index < k && prev; index++){ //μετακινουμε τον prev στον k-οστο κομβο ο οποιος ειναι αυτος απο τον οποιο θα βαλουμε στον επομενο του
			//τον καινουριο κομβο
				prev = prev->nextpos;
			}

			ChainNode<T> *n = new ChainNode<T>; //Δημιουργουμε τον νεο κομβο n
	
			n->time=t; 
			n->vel=v; 
			n->ispatient=isp; 
			n->positionx=posx; 
			n->positiony=posy;//Θετουμε σε αυτον ολες τις απαραιτητες τιμες των μεταβλητων
	
			if (k!=0) {//Αν το k δεν ειναι μηδεν σημαινει οτι θα προσθεσω ενδιαμεσο κομβο
				n->nextpos = prev->nextpos;//Θετω τον επομενο του καινουριου (n) να ειναι ο επομενος του prev (τωρα εχουν ιδιο επομενο)
				prev->nextpos = n;//Θετω τον επομενο του prev να ειναι ο n (οποτε τωρα εχει μπει ο n ενδιαμεσα στον p (k-οστο κομβο) και σε αυτον που ηταν μετα τον p) 
			}
			else {//Aν το k ειναι μηδεν
				n->nextpos = first; //Ο επομενος του n γινεται o first 
				first = n;//θετω πλεον τον first να ειναι ο n
			}
		
		}	




		void Output(int d){//Η συναρτηση αυτη τυπωνει ολους τους κομβους ξεκινοντας απο τον πρωτο της μερας που θα της πεις

			ChainNode<T> *tmp;//Φτιαξε εναν κομβο tmp

			tmp=first;//Θεσε τον tmp να ειναι ο first (ο first του object chain με το οποιο θα καλεσεις τη συναρτηση)
			
			for (int startnode=1; startnode<10*(d-1)+1; startnode++){
				tmp=tmp->nextpos;
			}//Ο tmp φτανει στον πρωτο κομβο της ημερας που δεχεται σαν ορισμα

			while(tmp != NULL){//Οσο ο tmp δεν ειναι null τυπωσε ολα τα στοιχεια του και πηγαινε στον επομενο
	
				cout <<"\nTime: "<< tmp->time<<endl;
				cout <<"Velocity to this position: "<< tmp->vel<<endl;
				cout <<"Is patient: "<< tmp->ispatient<<endl;
				cout <<"Position: "<<"(" << tmp->positionx << ","<<tmp->positiony<<")\n\n"<<endl;

				tmp = tmp->nextpos;
			}

		}


};

//#######################################################################################################################################




//Εδω οριζονται οι συναρτησεις POSSIBLE_COVID_19_INFECTION, FIND_CROWDED_PLACES, REPAIR και SUMMARIZE_TRAJECTORY, τα objects χρηστες, οπως επισης 
//και μερικες αλλες συναρτησεις και λιστες που θα χρησιμοποιηθουν για καποιες λειτουργιες


string returnbool(bool b){ //Συναρτηση που επιστρεφει σε string true η false (για ορισμα 1 η 0 αντιστοιχα)
	if (b){
		return "TRUE";
	}
	return "FALSE";
};



int randomnum;
int random_x;
int random_y;
int random_v;//Μεταβλητες που θα αποθηκευονται οι συντεταγμενες, η ταχυτητα και ενας τυχαιος αριθμος απο το 0 μεχρι το 4

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
Chain<int> U14;//Δημιουργια των objects χρηστων

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
Chain<int> LU14;//Δημιουργια των αντιγραφων objects χρηστων τα οποια θα χρησιμοποιηθουν για τη συναρτηση SUMMARIZE_TRAJECTORY

Chain<int> ch[14]={U1,U2,U3,U4,U5,U6,U7,U8,U9,U10,U11,U12,U13,U14}; 
Chain<int> ch2[14]={LU1,LU2,LU3,LU4,LU5,LU6,LU7,LU8,LU9,LU10,LU11,LU12,LU13,LU14};//Προσθετω τους χρηστες σε ενα array

int Patlist[10];//Λιστα στην οποια θα βαλουμε τους αριθμους (τα i) των ασθενων που νοσουν (Θα χρησιμοποιηθει στην συναρτηση POSSIBLE_COVID_19_INFECTION)
int listsize = 0;//Πληθος μη μηδενικων στοιχειων στη λιστα

bool searchi(int list[],int i){ //Αυτη η συναρτηση ειναι για να βρουμε καποιο συγκεκριμενο αριθμο ενος ασθενη στη λιστα αν υπαρχει.
//Αν υπαρχει επιστρεφει true αλλιως false
	
	for(int j=0; j<=listsize-1; j++){
		if (list[j] == i){
			return true;
		}
	}
	return false;	
}

addnodes(int s,int d,bool b,int i){ //Αυτη η συναρτηση δημιουργει κομβους για τους χρηστες, οι οποιοι περιεχουν τις πληροφοριες: συντεταγμενες,
//ταχυτητα (τυχαιες καθε φορα), δευτερολεπτα καταγραφης της θεσης μετα την εναρξη της ημερας και αν ο χρηστης ειναι ασθενης η οχι(TRUE Η FALSE αντιστοιχος).
	
	if (s==0 && d==1){ //Αν ειμαστε στην αρχη της πρωτης μερας δωσε ταχυτητα 0 αλλιως μια τυχαια (απο 3-6)
		random_v = 0;
	} else{ 
		random_v = (rand() % 4) + 3;
	}
	
	random_x =  (rand() % 11);//Δωσε τυχαιες συντεταγμενες (χ και ψ απο 0-10) 
	random_y =  (rand() % 11);
	int N = ch[i].Length();
	ch[i].Insert(N, s + 300*(d-1), random_v, returnbool(b), random_x, random_y); //Δημιουργια ενος κομβου με τα παραπανω στοιχεια
	//για τον i-οστο χρηστη(καθε φορα ο επομενος κομβος προστιθεται αμεσως μετα τον επομενο)
}






//REPAIR



REPAIR (int d,int i){ 
	
	//Για την εισαγωγη στον πρωτο κομβο
	
	int L = ch[i].Length();//Θετουμε L το μεγεθος της i-οστης αλυσιδας του χρηστη
	
	if (ch[i].first->time !=0){//Αν ο πρωτος κομβος δεν εχει time=0,τοτε δεν ειναι ο πρωτος και πρεπει δημιουργηθει
		
		random_x =  (rand() % 11);
		random_y =  (rand() % 11);//Θετουμε τυχαιες συντεταγμενες
		
		if (i==0 || i<=6){//Αν ο χρηστης ειναι απο τον 1ο μεχρι και τον 7ο(υγειης) κανε εισαγωγη σε αυτον τον χρηστη τον πρωτο κομβο με time=vel=ispatient=false 
		//και χ και ψ τις τυχαιες συντεταγμενες
			ch[i].Insert(0, 0, 0, returnbool(0), random_x, random_y);
			L+=1;//Αυξανω το μεγεθος της αλυσιδας
		}else{
			ch[i].Insert(0, 0, 0, returnbool(1), random_x, random_y);//Ομοιως αλλα εδω βαζω ispatient=true διοτι οι υπολοιποι χρηστες ειναι ασθενεις
			L+=1;//Αυξανω το μεγεθος της αλυσιδας
		}
				
	}
	
	
	//Για τον εισαγωγη στον τελευταιο κομβο
	
	ChainNode<int> *current = ch[i].first; //Δημιουργουμε εναν νεο κομβο και θετουμε current = first
	
	while(current->nextpos){ //Οσο ο current εχει επομενο
		current=current->nextpos; //πηγαινε στον επομενο κομβο (θετω current τον επομενο κομβο)
	}
	
	int lasttime = current->time;//Θετουμε lasttime το time του τελευταιου κομβου
	if ((lasttime+30)%300!=0){ //Αν ο lasttime δεν ειναι 270,570,870,...,2970 (αυτες ειναι οι τελευταιες καταγραφες time πριν ληξει η αντιστοιχη μερα)
	//πχ αν time=600 τοτε d=3			
		random_x =  (rand() % 11);
		random_y =  (rand() % 11);
		random_v = (rand() % 4) + 3;//Θετουμε τυχαια χ ψ και ταχυτητα
			
		if (i==0 || i<=6){
			ch[i].Insert(L, 270+(d-1)*300, random_v, returnbool(0), random_x, random_y);
			L+=1;//Αυξανω το μεγεθος της αλυσιδας
		}else{																			//Θετω στο τελευταιο κομβο το τελευταιο time της αντιστοιχης μερας
			ch[i].Insert(L, 270+(d-1)*300, random_v, returnbool(1), random_x, random_y); //(για υγειεις και ασθενεις)
			L+=1;//Αυξανω το μεγεθος της αλυσιδας
		}
			
	}
	
	
	//Για την εισαγωγη σε ενδιαμεσο κομβο
	
	bool flag = true;//Θετω μια μεταβλητη true
	
	for (int j=10*(d-1)+1; j<L; j++){ //Η επαναληψη ξεκιναει απο τον αριθμο του πρωτου κομβου εκεινης της μερας και φτανει μεχρι ενα πριν το μηκος της αλυσιδας
										//πχ αν d=2 η επαναληψη ειναι απο j=11 μεχρι j=19 (Καθε μερα δημιουργουνται 10 κομβοι)
	
		if( d!=1 && (j-1)%10==0 && flag ){//Στη περιπτωση που εχουμε j=11,21,31,...,91 (σε καποια μερα μετα την πρωτη) και το flag ειναι true
		//μειωσε το j κατα 1 και θεσε flag=false(Αυτο το κανουμε διοτι πχ για d=1 εχουμε απο j=1 μεχρι 9 οποτε και γινεται ο ελεγχος για τους κομβους
		//απο 2,1 μεχρι και 10,9.Την επομενη μερα για j=11 ελεγχονται οι 12,11 (χαθηκε ο ελεγχος 11,10) οποτε ειναι αναγκαιο αφου εχει δημιουργηθει
		//ο 11ος κομβος τη δευτερη μερα πλεον, να θεσω j=10 για να ελεγξω τους 11,10.flag=false για να μην ξαναγινει το ιδιο οταν γινει παλι j=11.) 	
			j -=1;
			flag = false;
		}
		
		
		if ((ch[i].GetNodeTime(j+1) - ch[i].GetNodeTime(j))!=30){//Αν η διαφορα του time του επομενου κομβου με τον παροντικο δεν ειναι 30
			
			random_v = (rand() % 4) + 3;
			random_x =  (rand() % 11);
			random_y =  (rand() % 11);
			
			
			if (i==0 || i<=6){
				ch[i].Insert(j, ch[i].GetNodeTime(j)+30, random_v, returnbool(0), random_x, random_y);
				L+=1;//Αυξανω το μεγεθος της αλυσιδας
			}else{																					  //Θεσε ενδιαμεσα τους εναν νεο κομβο που το time του 
				ch[i].Insert(j, ch[i].GetNodeTime(j)+30, random_v, returnbool(1), random_x, random_y);//θα ειναι κατα 30 μεγαλυτερο απο τον παροντικο
				L+=1;//Αυξανω το μεγεθος της αλυσιδας												 //(για υγειεις και ασθενεις)
			}
				
		} 
		
		if((j-1)%10==0){
			flag = true;
		} //flag=true ξανα οταν j=11,21,31,...,91 για δευτερη φορα
	} 		
}







//POSSIBLE_COVID_19_INFECTION



string POSSIBLE_COVID_19_INFECTION(int i,int d){
	ChainNode<int> *hcurrent; //Δημιουργουμε τον κομβο με ονομα hcurrent με τον οποιο θα προσπελασουμε τους κομβους των υγειη χρηστων
	int hx;
	int hy;//Μεταβλητες για να αποθηκευουμε τις συντεταγμενες χ και y του κομβου
		
	ChainNode<int> *pcurrent;//Δημιουργουμε τον κομβο με ονομα pcurrent με τον οποιο θα προσπελασουμε τους κομβους των ασθενων
	int px;
	int py;//Μεταβλητες για να αποθηκευουμε τις συντεταγμενες χ και y του κομβου
	
	ChainNode<int> *checknodes;//Κομβος με το ονομα checknode με τον οποιο θα ελεγχουμε αν μπορει να γινει ολοκληρομενος ελεγχος
	//για το αν νοσησε ενας χρηστης μεσα στη μερα.
	
	int index; 
	
	int C1=-30; //Μετρητης για το διαστημα που εμεινε ο χρηστης εντος της ακτινας ενος ασθενη
	int C2=-30; //Μετρητης για το διαστημα που μπορει να επηρεασει ενας κυκλος ενος ασθενη καποιο χρηστη

	
	for(int j=7; j<=13; j++){ //Συγκρινω τις τροχιες ολων των ασθενων (8ο εως 14ο στοιχειο του array) με τον i-οστο χρηστη
	
		if (d==1){ //Αν ειμαστε στην πρωτη μερα ακολουθουν τα παρακατω
			hcurrent = ch[i].first; //Καθε φορα μετα την επαναληψη θετουμε στην hcurrent τον πρωτο κομβο του i-οστου υγειη χρηστη
			hx = hcurrent->positionx;
			hy = hcurrent->positiony;//Αποθηκευουμε τις συντεταγμενες χ και y του πρωτου κομβου σε 2 μεταβλητες καθε φορα μετα την επαναληψη
				
			index = 1; //Η διαδικασια συγκρισης των συντεταγμενων του i-οστου χρηστη με τις αντιστοιχες συντεταγμενες του 
				//j-οστου ασθενη ξεκινα απο τους πρωτους τους κομβους
		}
		
		if(d!=1){//Αν δεν ειμαστε στην πρωτη μερα ακολουθουν τα παρακατω
				
			index=5+10*(d-2); //Η διαδικασια συγκρισης του i-οστου χρηστη με τον καθε j-οστο ασθενη ξεκινα απο τους κομβους 5,15,25,...,85 του καθενος για
			//d=2,3,4,...,10 αντιστοιχα
				
			hcurrent = ch[i].first;
			 
			for(int k=1; k<index; k++){
				hcurrent=hcurrent->nextpos; //Καθε φορα μετα την επαναληψη θετουμε στην hcurrent τον πρωτο κομβο του i-οστου υγειη χρηστη
				//και την μετακινουμε μεχρι να φτασει τον καταλληλο αρχικο κομβο (αναλογα τη μερα και το index).
			}
				
		}
			
			
		pcurrent = ch[j].first; //Καθε φορα μετα την επαναληψη θετουμε στην pcurrent τον πρωτο κομβο του j-οστου ασθενη
		px = pcurrent->positionx;
		py = pcurrent->positiony;//Αποθηκευουμε τις συντεταγμενες χ και y του πρωτου κομβου σε 2 μεταβλητες καθε φορα μετα την επαναληψη
			
		for(int k=1; k<index; k++){//Αν d=index=1 τοτε δεν μετακινουμε τον pcurrent
			
			pcurrent = pcurrent->nextpos;
			px = pcurrent->positionx;
			py = pcurrent->positiony;//Αναλογα τη μερα και το index μετακινουμαστε στον καταλληλο κομβο του j-οστου ασθενη(τωρα πια οι hcurrent και η pcurrent
			//βρισκονται σε αντιστοιχους κομβους)πχ για d=4 ειναι index=25 οποτε η συγκριση ξεκινα απο τους 25ους κομβους του ασθενη και του χρηστη 
			
		}
			
		int validcheckcounter = 1;  //Με αυτον τον μετρητη ελεγχουμε αν υπαρχουν 6 παρακατω κομβοι διαθεσιμοι απο αυτον που ειμαστε
			
		while(true){ //Η διαδικασια αποδω και κατω για τη συγκριση ενος i-στου υγειη χρηστη με εναν j-οστο ασθενη ειναι η ακολουθη:
			
			//Αρχικα ξεκιναμε απο τους πρωτους κομβους του ασθενη και του χρηστη.Οσο ειμαι στον πρωτο κομβο του ασθενη,ελεγχω τις συντεταγμενες του
			//πρωτου κομβου του υγειη οπως και τις συντεταγμενες στους 6 επομενους κομβους απο αυτον (διαρκεια 180") για να δω εαν ο υγειης χρηστης εμεινε
			//για 60" στην ακτινα του πρωτου κομβου του ασθενη (ακτινα 2 μετρων) οσο αυτη ηταν ενεργη (διαρκεια 180").Αν ο χρηστης παρεμεινε οσο επρεπε 
			//στην ακτινα ενω αυτη ηταν ενεργη, η συναρτηση επιτρεφει TRUE για αυτον, αλλιως FALSE.Στη συνεχεια αρχιζω ξανα τη διαδικασια για τον ιδιο χρηστη
			//και ασθενη, αλλα με αρχικους κομβους τους 2ους τους.Οταν φτασω σε κομβους που δεν εχουν 6 επομενους την ιδια μερα,τοτε η διαδικασια προχοραει 
			//για τον ιδιο χρηστη,σε διαφορετικο ασθενη(ξεκινοντας παλι απο τους πρωτους τους κομβους) μεχρι να ελεγξω ολους τους ασθενης με αυτον τον 
			//χρηστη εκεινη τη μερα.Οσο για τους κομβους που παρελειψα να ελεγξω την προηγουμενη μερα
			//για τον χρηστη, τους ελεγχω την επομενη μαζι με καποιους της καινουριας μερας.Ολη αυτη η διαδικασια επαναλαμβανεται για ολους τους 7 χρηστες
			//μεσα στη μερα και για ολες τις 10 μερες.
					
			checknodes = hcurrent; //Ο ελεγχος για το αν υπαρχουν 6 διαθεσιμοι μεταγενεστεροι κομβοι ξεκιναει απο τον κομβο hcurrent
					
			while(checknodes->nextpos){ //Οσο ο checknodes εχει επομενο κομβο
						
				checknodes=checknodes->nextpos; //Θεσε τον checknodes στον επομενο
				validcheckcounter+=1; //Αυξησε τον μετρητη κατα 1

				if(validcheckcounter==7){ //Αν ο μετρητης γινει 7 αυτο σημαινει οτι υπαρχουν 6 μεταγενεστεροι κομβοι και μπορει να γινει
				//ολοκληρωμενος ελεγχος για το αν ο χρηστης νοσησε εκεινη τη μερα, με αφετηρια τον hcurrent. 
					break ;	
				}
					
			}
				
			if(index<95){//Οι συνολικοι κομβοι για καθε χρηστη ειναι 100 (για ολες της μερες) επομενος αν φτασουμε στον 95ο ενος χρηστη προφανως 
			//δεν υπαρχουν 6 μεταγενεστεροι αλλα ειναι πιθανο να νοσησει ο χρηστης αν οι hcurrent και pcurrent εχουν αφετηρια τον 95ο μεχρι και τον 98ο 
			//κομβο οποτε θελουμε να ελεγξουμε και τους 95-98.
				
				if(validcheckcounter!=7){ //Αν το index<95 και ο μετρητης δεν ειναι 7 αυτο σημαινει οτι δεν μπορει να γινει ολοκληρωμενος ελεγχος
				//εκεινη τη μερα και θα γινει την επομενη
					break;
				}
			}
					
									    
			while(C2!=180){ //Οσο ο μετρητης C2 δεν ειναι 180(Δηλαδη ο κυκλος του j-οστου ασθενη μπορει να επηρασει καποιον χρηστη)
		
				if((px==hx && py==hy)||(px+2==hx && py==hy)||(px-2==hx && py==hy)||(px==hx && py+2==hy)||(px==hx && py-2==hy)||
				(px+1==hx && py+1==hy)||(px-1==hx && py-1==hy)||(px-1==hx && py+1==hy)||(px+1==hx && py-1==hy)||(px+1==hx && py==hy)||
				(px-1==hx && py==hy)||(px==hx && py+1==hy)||(px==hx && py-1==hy)){ //Αν ο i-οστος χρηστης βρισκεται σε "ακτινα 2 μετρων" απο τον j-οστο ασθενη
						
					C1+=30; //Την πρωτη φορα ο μετρητης φτανει στο 0 και αυξανεται κατα 30 αν ο χρηστης βρεθει ξανα στα επομενα 30" στην "ακτινα" του ασθενη
				
				}else{
					
					C1=-30;//Αν ο i-οστος χρηστης δε βρισκεται σε "ακτινα 2 μετρων" απο τον j-οστο ασθενη θεσε ξανα τον μετρητη c2 = -30
				}
						
				C2+=30; //Καταγραφει τη διαρκεια που ειναι ενεργη η ακτινα του j-οστου ασθενη
		
				if(C2!=180 && C1==60){ //Αν δεν εχει ληξει η διαρκεια της ακτινας και ο χρηστης βρισκεται εντος της ακτινας του j-οστου ασθενη 
				//για 60" ο i-οστος χρηστης ειναι πιθανων ασθενης
							
					Patlist[listsize]=i;//Βαλε στη λιστα τον αριθμο του i-οστου χρηστη που νοσησε.
					listsize+=1;//Αυξησε το πληθως των μη μηδενικων στοιχειων της						
					return "TRUE";//Επεστρεψε true
				}
		
				if(C2!=180){ //Οσο δεν εχει ληξει η διαρκεια της ακτινας ελεγξε τις επομενες συντεταγμενες του i-στου χρηστη μεχρι να φτασουμε σε αυτες που καταγραφτηκαν
				//τη στιγμη που εληξε η ακτινα
					if(!(hcurrent->nextpos)){ //Αν εντοπισουμε οτι δεν υπαρχει επομενος κομβος και ειναι ακομα ενεργη η ακτινα 
					//(Στη περιπτωση που εχουμε φτασει στον 100οστο κομβο του υγειη) συνεχισε τη διαδικασια
						break;
					}
					hcurrent=hcurrent->nextpos;
					hx = hcurrent->positionx;
					hy = hcurrent->positiony;
				}
				
			}
			
			pcurrent=pcurrent->nextpos; //Παω στον επομενο κομβο του ασθενη		
			px = pcurrent->positionx;
			py = pcurrent->positiony;//αποθηκευω τις συντεταγμενες του
					
			hcurrent=ch[i].first;//Παω στον πρωτο κομβο του υγειη
		
			for(int i=1; i<=index; i++){
					
				hcurrent=hcurrent->nextpos; 												
			}//Παω συνεχεια στον επομενο κομβο του υγειη μεχρι να φτασω στον αντιστοιχο του ασθενη.Πχ αν του ασθενη ειναι ο 3ος (index = 2) τοτε
			//προχορω δυο θεσεις απο τον αρχικο του υγειη για να φτασω στον 3ο.
			hx = hcurrent->positionx;
			hy = hcurrent->positiony;//αποθηκευω τις συντεταγμενες εκεινου του κομβου του υγειη
					
			C1=-30;
			C2=-30;//Θετω ξανα τους μετρητες -30
			index+=1; //Αυξανω το index για να λειτουργησει σωστα την επομενη φορα η παραπανω διαδικασια				
			validcheckcounter = 1;
					
			if (index==99){ //Αν βρισκομαστε στον κομβο 99 ο χρηστης δεν ειναι δυνατο να νοσησει οποτε επιστρεφεται false
				return "FALSE";
			}
		}
	}	
		
	return "FALSE"; //Αν μετα τη συγκριση καθε ασθενη με τον i-οστο χρηστη για εκεινη την ημερα δεν βγει οτι νοσησε ο χρηστης επιστρεφεται false
}






//SUMMARIZE_TRAJECTORY




SUMMARIZE_TRAJECTORY(int d,int i,int sumday){
	
	ChainNode<int> *specificdnd = ch2[i].first; //Θετουμε specificdnd τον πρωτο κομβο του αντιγραφου i-οστου χρηστη
		
	ChainNode<int> *tmpnd;//Στον tmpnd θα αποθηκευουμε προσωρινα τον κομβο που θα θελουμε να διαγραψουμε
	ChainNode<int> *prevspecificdnd; //Σε αυτον θα αποθηκευουμε παντα τον προηγουμενο απο αυτον που ειναι πιθανο οτι θα διαγαψουμε
	bool flag = true; 
	int dfx;
	int dfy;//Μεταβλητες στις οποιες αποθηκευουμε τις συντεταγμενες του πρωτου κομβου
	int dsx;
	int dsy;//Μεταβλητες στις οποιες αποθηκευουμε τις συντεταγμενες του δευτερου κομβου
	//Καθε φορα ελεγχουμε τον δευτερο με βαση τον πρωτο κομβο.Δευτερο θα λεμε αυτον που ελεγχουμε αν ειναι εντος ακτινας 3 μετρων απο τον πρωτο 		
		
	while((specificdnd->time)!=300*(sumday-1)){	//Οσο το time του specificdnd δεν ειναι το πρωτο της αντιστοιχης μερας προχωρα στον επομενο κομβο
	//(Ετσι φτανουμε στον πρωτο κομβο της αντιστοιχης μερας χωρις να γνωριζουμε ποσοι εχουν σβηστει)
		specificdnd=specificdnd->nextpos;
	}
		
	for (int index=1; index<10; index++){//Γινεται ελεγχος απο τον πρωτο κομβο της αντιστοιχης μερας μεχρι και τον τελευταιο της αντιστοιχης μερας
		dfx=specificdnd->positionx;
		dfy=specificdnd->positiony;//θεσε στα dfx και dfy τις συντεταγμενες χ και y αντιστοιχα που εχει ο specificdnd εκεινη τη στιγμη
		//(Αποθηκευουμε τις συντεταγμενες του πρωτου)
		prevspecificdnd=specificdnd;//Θετουμε τον prevspecificdnd να ειναι στο ιδιο σημειο με τον specificdnd πριν μπουμε στην επαναληψη while
		//(Θετουμε εναν κλονο του πρωτου)

		while(true){//Ως αναφορα τον πρωτο κομβο, οσο ο δευτερος ειναι εντος της ακτινας του πρωτου σβηστον και συνεχισε να ελεγχεις τους υπολοιπους.
		//Οταν βρεις καποιον που δεν ειναι στην ακτινα, βγες απο τη while και θεωρησε πρωτο αυτον που δεν ηταν στην ακτινα.
		
			if(flag==true){//Αν το flag ειναι true προχορα στον επομενο κομβο 
				specificdnd=specificdnd->nextpos;
			}

			dsx=specificdnd->positionx;
			dsy=specificdnd->positiony;//Αποθηκευουμε τις συντεταγμενες του δευτερου κομβου

			if((dfx==dsx && dfy==dsy)||(dfx+2==dsx && dfy==dsy)||(dfx-2==dsx && dfy==dsy)||(dfx==dsx && dfy+2==dsy)||(dfx==dsx && dfy-2==dsy)||
			(dfx+1==dsx && dfy+1==dsy)||(dfx-1==dsx && dfy-1==dsy)||(dfx-1==dsx && dfy+1==dsy)||(dfx+1==dsx && dfy-1==dsy)||(dfx+1==dsx && dfy==dsy)||
			(dfx-1==dsx && dfy==dsy)||(dfx==dsx && dfy+1==dsy)||(dfx==dsx && dfy-1==dsy)||(dfx+3==dsx && dfy==dsy)||(dfx-3==dsx && dfy==dsy)||
			(dfx==dsx && dfy+3==dsy)||(dfx==dsx && dfy-3==dsy)||(dfx-2==dsx && dfy-2==dsy)||(dfx+2==dsx && dfy+2==dsy)||(dfx+2==dsx && dfy-2==dsy)||
			(dfx-2==dsx && dfy+2==dsy)||(dfx+2==dsx && dfy-1==dsy)||(dfx+2==dsx && dfy+1==dsy)||(dfx-2==dsx && dfy+1==dsy)||(dfx-2==dsx && dfy-1==dsy)||
			(dfx+1==dsx && dfy+2==dsy)||(dfx+1==dsx && dfy-2==dsy)||(dfx-1==dsx && dfy+2==dsy)||(dfx-1==dsx && dfy-2==dsy))
			{//Αν οι συντεταγμενες του δευτερου βρισκονται εντος ακτινας 3 μετρων απο αυτες του πρωτου	
				tmpnd=specificdnd; //Θεσε τον δευτερο temp
				specificdnd=specificdnd->nextpos; //Προχορα στον επομενο κομβο(τον ονομαζουμε 3ο. Ο 3ος θα παιξει τον ρολο ενος νεου δευτερου
				//μετα τη διαγραφη του νυν δευτερου)
				prevspecificdnd->nextpos=tmpnd->nextpos;//Ο επομενος του 1ου γινεται ο 3ος (τωρα ο 1ος και ο 2ος εχουν τον ιδιο επομενο κομβο)
				index++;//Αυξανω το index διοτι εχω προχορησει δευτερη φορα
				delete tmpnd;//Σβηνω τον tmpnd (ειναι ο 2ος)
				flag=false;	//Θετω το flag false για να μην προχορησω στον επομενο κομβο οταν θα ξανατρεξω τη while (Η while τρεχει ξανα οταν σβηστει
				//καποιος 2ος κομβος)
				if(index==10){
					break;
				}	
							
			}else{//Αν ο δευτερος δεν ειναι εντος της ακτινας του πρωτου τοτε βγες απο την επαναληψη  
				flag=true;//θεσε flag = true ετσι ωστε οταν ξαναμπεις στη while να προχορησεις στον επομενο κομβο
				break;
			}
		}
			
	}
	
}






//FIND_CROWDED_PLACES



int users;//Global μεταβλητη users, υπολογιζει ποσοι χρηστες βρεθηκαν στη καταλληλη περιοχη την αντιστοιχη μερα (ειναι ορατη και στην main για να 
//μπορει να την εμφανισει οταν τρεξει η FIND_CROWDED_PLACES για ολους τους
//χρηστες και υπολογισει ποσοι βρεθηκαν στη καταλληλη περιοχη)

FIND_CROWDED_PLACES(int d, int i, int timeinterval, int squaredimensions, int squarelowerlefttcornerx, int squarelowerlefttcornery, int minimumstay){
		
	ChainNode<int> *current = ch[i].first;//Θετουμε current τον πρωτο κομβο του i-οστου χρηστη
	int Cti=-30;//Μετρητης που μετραει τη διαρκεια που ειναι ενεργη η περιοχη
	int Cms=-30;//Μετρητης που μετραει ποση ωρα εμεινε ενας χρηστης στη περιοχη
	if(i==0){//Πριν ξεκινησεις να ελεγχεις για τον πρωτο χρηστη, θεσε users=0 (δεν εχει μετρηθει καποιος χρηστης ακομα)
		users=0;
	}
		
	for(int index=1; index<10*(d-1)+1; index++){
		current=current->nextpos;
	}//Ο current φτανει στον πρωτο κομβο της αντιστοιχης ημερας
		
	int ux = current->positionx;
	int uy = current->positiony;//Αποθηκευσε τις συντεταγμενες του πρωτου κομβου της αντιστοιχης ημερας 
	
	while(Cti!=timeinterval){//Οσο η περιοχη ειναι ακομα ενεργη (αυτο σημαινει, οσο βρισκομαστε ακομα στο χρονικο διαστημα που μας ενδιαφερει για να 
	//εξετασουμε την περιοχη)
			
		Cti+=30; //Αυξησε τον μετρητη διαρκειας της περιοχης (την πρωτη φορα φτανει στο 0 αφου βρισκομαστε στον πρωτο κομβο) 
			
		if(ux>=squarelowerlefttcornerx && ux<=(squaredimensions+squarelowerlefttcornerx) &&
		uy>=squarelowerlefttcornery && uy<=(squaredimensions+squarelowerlefttcornery)){//Αν ο χρηστης βρισκεται εντος της περιοχης				
			Cms+=30;//Αυξησε τον μετρητη που μετραει τη διαρκεια διαμονης του χρηστη στη περιοχη (την πρωτη φορα φτανει στο 0 
			//αφου μολις βρεθηκαμε στην περιοχη) 
		}else{				
			Cms=-30;//Αν ο χρηστης δεν βρισκεται στη περιοχη θεσε ξανα Cms=-30;
		}
			
		if(Cms==minimumstay&&Cti!=timeinterval){//Αν ο χρηστης βρισκεται στην περιοχη για το ελαχιστο απαιτουμενο χρονικο διαστημα και βρισκομαστε ακομα στο
		//χρονικο διαστημα που μας ενδιαφερει, αυξησε κατα 1 το πληθος των χρηστων που ανιχνευτηκαν στη περιοχη και σταματα τη διαδικασια για αυτον τον χρηστη
			users++;
			break;
		}
			
		if(Cti!=timeinterval){//Αν δεν εχει ληξει το χρονικο διαστημα που μας ενδιαφερει, προχορα στον επομενο κομβο και αποθηκευσε τις συντεταγμενες του
			current=current->nextpos;
			ux = current->positionx;
			uy = current->positiony;
		}
	}
	
}



//Εκκινηση του προγραμματος



int main(){

	srand(time(NULL));// Για να αποθηκευονται τυχαιοι αριθμοι καθε φορα στις μεταβλητες μας

	for (int d=1; d<=10; d++){ //Καθε μερα προσθετει 10 κομβους για τον καθε χρηστη

		for(int s=0; s<=270; s+=30){ //Καθε "30 δευτερολεπτα" προσθετει εναν νεο κομβο για τον καθε χρηστη μεχρι το τελος της μερας
		                                 

			//Δημιουργια 7 ασθενων και 7 υγειη χρηστων
		
		
	 		for (int i=0; i<=6; i++){ //Φτιαχνει κομβους για τους πρωτους 7 χρηστες (Υγειης)
	 
				randomnum =  (rand() % 5); //Διαλεγουμε τυχαιο αριθμο απο το 0-4
			
		
				if (randomnum==2){ //Αν ο αριθμος ειναι 2, δεν καταγραφεται κομβος εκεινη τη στιγμη (Αρα 20% πιθανοτητα να συμβει αυτο) 
					continue;
				}else{
					addnodes(s,d,0,i);
				}		
			}
	
		
	
			for (int i=7; i<=13; i++){ //Φτιαχνει κομβους για τους υπολοιπους 7 χρηστες (Ασθενης)
		
				randomnum =  (rand() % 5);
			
				if (randomnum==2){ 
					continue;
				}else{
					addnodes(s,d,1,i);
				}	
			}
		
		}
	
	
	
	
//Στο τελος της καθε μερας εκτελουνται οι συναρτησεις



		cout<<"\n\n\n   						      DAY "<<d<<"\n\n\n"<<endl;;		
	
		string s;
		//Εκτυπωνονται οι πρωτοι 10 κομβοι της ημερας του ατομου που θα επιλεξει ο χρηστης
		cout<<"TRAJECTORIES FOR ALL 14 USERS HAVE BEEN SUCCESSFULLY CREATED FOR DAY "<<d<<endl;
		while(true){
			
			cout<<"\nPLEASE INSERT THE NUMBER (1-14) OF THE USER YOU WANT TO VIEW IT'S TRAJECTORY.WRITE 'NEXT' IF YOU WANT TO RUN THE REPAIR FUNCTION.";
			cin>>s; //Ζηταει απο τον χρηστη να δωσει τον αριθμο του ατομου για το οποιο θελει να γινει η λειτουργια για εκεινη τη μερα
			if (s=="NEXT"){
				break;
			}//Αν ο χρηστης θελει να προχορησει στην επομενη λειτουργια πρεπει να γραψει "NEXT"
	
			stringstream toint(s);//Μεταφραζει το string (που ειναι ο αριθμος του χρηστη) σε αριθμο
			int i;
			toint>>i;//Στη περιπτωση που ο χρηστης δεν δωσει αριθμο το μεταφραζει σε 0 οποτε i=0.
	
			if(i<1||i>14){//Αν ο χρηστης δωσει λανθασμενο αριθμο του ζητειται ξανα αριθμος
				cout<<"\nPLEASE INSERT A VALID NUMBER"<<endl;
			}else{
				cout<<"\nTRAJECTORY OF USER "<<i<<" AT DAY "<<d<<" IS:\n"<<endl;
				ch[i-1].Output(d);//Αν δωσει σωστο αριθμο εκτελειται η Output για το ατομο που επελεξε ο χρηστης τη μερα εκεινη 
				//(τυπωνει τους κομβους του ατομου της αντιστοιχης μερας)
			}
	
		}






//Επιδιορθωνονται οι κομβοι της συγκεκριμενης μερας για ολους τους χρηστες (REPAIR)



		for(int i=0; i<=13; i++){
			REPAIR (d, i);//Η συναρτηση περνει ως εισοδο τη μερα και καθε i-οστο χρηστη
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
			toint>>i;//Στη περιπτωση που ο χρηστης δωσει string το μεταφραζει σε 0 οποτε i=0.
	
			if(i<1||i>14){
				cout<<"\nPLEASE INSERT A VALID NUMBER"<<endl;
			}else{
				cout<<"\nREPAIRED TRAJECTORY OF USER "<<i<<" AT DAY "<<d<<" IS:\n"<<endl;
				ch[i-1].Output(d);		
			}
	
		}





//Συγκρινει τις τροχιες ολων των υγειων χρηστων με τις τροχιες ολων των ασθενων για τη συγκεκριμενη μερα(και για ενα μικρο διαστημα της προηγουμενης, βλεπε
//τη περιγραφη της για περισσοτερα) (POSSIBLE_COVID_19_INFECTION)



		string z;

		for (int i=0; i<=6; i++){//Για καθε υγειη χρηστη
		
			if(searchi(Patlist,i)==true){//Αν ενας i-οστος υγειης χρηστης ειναι ασθενης την μια μερα, εχει μπει στη λιστα και την επομενη μερα δεν εξεταζεται ξανα
				continue;
			}

			z=POSSIBLE_COVID_19_INFECTION(i, d);//Η συναρτηση περνει ως εισοδο τη μερα και τον i-οστο χρηστη(μονο τους υγειης) και αποθηκευει στο z καθε φορα τα αποτελεσματα
			//για τον καθε χρηστη

			if (d==1){
				cout<<"\nPOSSIBLE INFECTION OF USER "<<i+1<<" AT DAY 1 "<<z<<endl; //Την πρωτη μερα θα εμφανισει αυτο το μηνημα για τον καθε υγειη χρηστη
			}
			else{
				cout<<"\nPOSSIBLE INFECTION OF USER "<<i+1<<" AT DAY "<<d<<" OR NEAR THE END OF THE PREVIOUS DAY: "<<z<<endl;
				//Τις υπολοιπες μερες θα εμφανισει αυτο το μηνημα για τον καθε υγειη χρηστη 
			}		
	
		}
		
		cout<<"\nUSERS WHO HAVE BEEN POSSIBLE INFECTED UNTIL NOW: ";

		for(int i=0; i<=listsize-1; i++){
			cout<<"U"<<Patlist[i]+1<<" ";
		}
		cout<<"\n"<<endl; //Εμφανιζει οσους χρηστες εχουν νοσησει μεχρι τωρα

		while (true){
			cout<<"WRITE 'NEXT' IF YOU WANT TO RUN THE SUMMARIZE_TRAJECTORY FUNCTION.";
			cin>>s;
			if (s=="NEXT"){
				break;
			}
		}





//Δημιουργει μια συνοψη της τροχιας της μερας η οποια απεχει ενα πληθος ημερων που οριζει ο χρηστης απο τη συγκεκριμενη μερα (SUMMARIZE_TRAJECTORY)



		int db;
		int sumday;
		bool dontshowtxt=false;
		bool dontshowtxt2=true;//Μεταβλητς που ελεγχουν την εμφανιση καποιων μηνηματων

		if(d==1){//Τη πρωτη μερα δινεται η δυνατοτητα στον χρηστη να επιλεξει ποσες μερες πριν απο τη συγκεκριμενη θα γινεται η συνοψη
	
			while(!(db>0 && db<10)){//Οσο ο χρηστης δινει λανθασμενη αποσταση ημερων του ζητειται να ξαναδωσει
		
				string sdb;
				cout<<"\nINSERT THE AMOUNT (1-9) OF HOW MANY DAYS BEFORE YOU WANT MAKE THE TRAJECTORY SUMMARIZATION(THIS AMOUNT WILL BE THE SAME FOR THE REST DAYS):";
				cin>>sdb;
		
				stringstream toint2(sdb);//Μεταφραζει την εισοδο του χρηστη σε int
				toint2>>db;//Στη περιπτωση που ο χρηστης δωσει string το μεταφραζει σε 0 οποτε db=0.
	
				if(!(db>0 && db<10)){
					cout<<"\nPLEASE INSERT A VALID AMOUNT"<<endl;
				}
			}	
		}

		for (int i=0; i<=13; i++){//Εδω, γινεται η εξης διαδικασια: Δημιουργουνται 14 αντιγραφα των χρηστων,στα οποια προστιθενται οι 10-κομβοι τις αντιστοιχης μερας 
		//καθε φορα απο τους αντιστοιχους αυθεντικους χρηστες. Για αυτη τη συναρτηση χρησιμοποιουμε τα αντιγραφα των χρηστων καθε μερα, τα οποια δημιουργουνται σε αυτο 
		//το σημειο του κωδικα, για να μην αλλαξουμε τους κομβους των αυθεντικων χρηστων και επηρεασουμε τη λειτουργια των προηγουμενων συναρτησεων την επομενη μερα.
 
			ChainNode<int> *fln = ch[i].first; //Θετουμε fln τον πρωτο κομβο του i-οστου χρηστη

			for(int k=1; k<10*(d-1)+1; k++){//Φτανουμε στον πρωτο κομβο της αντιστοιχης ημερας
				fln=fln->nextpos;
			}

			int L2=ch2[i].Length();//Θετουμε L2 το length του i-οστου αντιγραφου
			ch2[i].Insert(L2, fln->time, fln->vel, fln->ispatient, fln->positionx, fln->positiony);//Δημιουργουμε με βαση το L2 τον πρωτο κομβο της αντιστοιχης μερας
			//στο i-οστο αντιγραφο και του προσθετουμε τα στοιχεια του αντιστοιχου πρωτου (για εκεινη την ημερα) αυθεντικου κομβου

	
			for(int j=1; j<10; j++){
	
				fln=fln->nextpos;
				L2=ch2[i].Length();
				ch2[i].Insert(L2, fln->time, fln->vel, fln->ispatient, fln->positionx, fln->positiony);

			}//Δημιουργουμε ολους τους υπολοιπους κομβους του i-οστου αντιγραφου για εκεινη τη μερα

			sumday=d-db;//Μεταβλητη η οποια εκφραζει την μερα που θα γινει η συνοψη
 
			if(sumday>0){//Αν ισχυει αυτο,τοτε βρισκομαστε στην καταλληλη μερα για να γινει συνοψη σε αυτη που μας ενδιαφερει (και απεχει απο την παροντικη κατα db)
	
				dontshowtxt2=false;
				SUMMARIZE_TRAJECTORY(d,i,sumday);//Καλειται η συναρτηση για να δημιουργησει (αν ειναι εφικτο) την συνοψη της ημερας που θελουμε στο i-οστο αντιγραφο	

			}else{
			//Αλλιως εμφανισε αυτο το μηνημα
				if(dontshowtxt==false){
					cout<<"\nTHERE IS NOT A DAY THAT HAS A DISTANCE OF "<<db<<" DAY(S) FROM DAY "<<d<<endl;
					dontshowtxt = true;//Αν εμφανισει μια φορα αυτο το μηνημα στην επαναληψη, τοτε δεν το ξαναεμφανιζει για εκεινη τη μερα αφου dontshowtxt = true
				}
			}

		}

		if(dontshowtxt2==false){//Αν εχει γινει συνοψη καποιας μερας δινεται η δυνατοτητα στον χρηστη να δει τα αποτελεσματα τις επιλογης του
	
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
					ch2[i-1].Output(1);//Τυπωνει τους κομβους του ατομου που επελεξε ο χρηστης απο την πρωτη μερα μεχρι και τη παροντικη (για να ειναι ορατες οι αλλαγες της
					//συνοψης για ολες τις προηγουμενες μερες)
				}
	
			}
	
		}





//Δινει τη δυνατοτητα στον χρηστη να δημιουργησει μια τετραγωνικη περιοχη (διαφορετικη για καθε μερα) εντος της περιοχης που εξεταζουμε (10x10) και να εξετασει 
//ποσα ατομα βρεθηκαν μεσα σε αυτη και παρεμειναν για ενα χρονικο διαστημα που οριζει αυτος και για μια χρονικη περιοδο που οριζει επισης αυτος.
//Η χρονικη περιοδος που εξεταζουμε ξεκινα απο την αρχη της ημερας.
//(FIND_CROWDED_PLACES)



		int timeinterval=0;
		int squaredimensions;
		int squarelowerlefttcornerx;
		int squarelowerlefttcornery;
		int minimumstay=0;//Μεταβλητες που θα αποθηκευτουν τα στοιχεια που θα δωσει ο χρηστης

		while(true){
	
			while(!(timeinterval>0 && timeinterval<=270 && timeinterval%30==0)){//καθε φορα που τρεχουμε αυτο το σημειο του κωδικα ειναι timeinterval=0
			//οποτε και ζητειται καθε μερα διαφορετικη τιμη απο το χρηστη
				cout<<"\nINSERT THE TIMEINTERVAL OF THE SQUARE REGION (MUST BE MULTIPLE OF 30 AND BETWEEN 30-270):";
				string stimeinterval;
				cin>>stimeinterval;//Ο χρηστης δινει τη χρονικη περιοδο που τον ενδιαφερει να εξετασει 
	
				stringstream toint(stimeinterval);
				toint>>timeinterval;
				if(!(timeinterval>0 && timeinterval<=270 && timeinterval%30==0)){
					cout<<"\nPLEASE INSERT A VALID TIMEINTERVAL"<<endl;//Αν ο χρηστης εχει δωσει string η λαθος αριθμο ξαναζητειται τιμη
				}
			}
	
			while(!(minimumstay>0 && minimumstay<=270 && minimumstay%30==0)){//καθε φορα που τρεχουμε αυτο το σημειο του κωδικα ειναι minimumstay=0
			//οποτε και ζητειται καθε μερα διαφορετικη τιμη απο το χρηστη
				cout<<"\nINSERT THE MINIMUM STAY DURATION OF THE SQUARE REGION (MUST BE MULTIPLE OF 30 AND BETWEEN 30-270):";
				string sminimumstay;
				cin>>sminimumstay;//Ο χρηστης δινει τη χρονικη διαρκεια που τον ενδιαφερει να εξετασει αν παρεμεινε καποιος χρηστης στη περιοχη που θα ορισει
	
				stringstream toint(sminimumstay);
				toint>>minimumstay;
				if(!(minimumstay>0 && minimumstay<=270 && minimumstay%30==0)){
					cout<<"\nPLEASE INSERT A VALID MINIMUM STAY DURATION"<<endl;//Αν ο χρηστης εχει δωσει string η λαθος αριθμο ξαναζητειται τιμη
				}
			}
			
			while(true){
	
				cout<<"\nINSERT THE X POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";
				while(!(cin>>squarelowerlefttcornerx)){//Εδω ζητειται συνεχως η τιμη χ της κατω αριστεραα γωνιας της περιοχης απο τον χρηστη (μεχρι να δωσει αριθμο)
					cin.clear(); 
    				cin.ignore(INT_MAX, '\n'); 
    				cout<<"\nPLEASE INSERT A VALID X POSITION"<<endl;
    				cout<<"\nINSERT THE X POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";
				}
				if(squarelowerlefttcornerx>=0&&squarelowerlefttcornerx<10){//Αν δωσει αριθμο ελεγχεται αν ειναι μεσα στα σωστα πλαισια (0-9 αφου η κατω αριστερα
				//γωνια της περιοχης που θα ορισουμε δεν γινεται να βρισκεται στη δεξια πλευρα της 10x10 περιοχης μας) και αν ειναι στα σωστα πλαισια ζητειται 
				//η επομενη τιμη αλλιως ζητειται ξανα η ιδια
					break;
				}else{
					cout<<"\nPLEASE INSERT A VALID X POSITION"<<endl;
				}		
				
			}
	
			while(true){
	
				cout<<"\nINSERT THE Y POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";//ομοιως για το y
				while(!(cin>>squarelowerlefttcornery)){
					cin.clear(); 
    				cin.ignore(INT_MAX, '\n'); 
    				cout<<"\nPLEASE INSERT A VALID Y POSITION"<<endl;
    				cout<<"\nINSERT THE Y POSITION OF THE SQUARE'S LOWER LEFT CORNER (MUST BE BETWEEN 0-9):";
				}
				if(squarelowerlefttcornery>=0&&squarelowerlefttcornery<10){//Εδω δεν γινεται η κατω αριστερα γωνια της περιοχης μας να ειναι στη πανω πλευρα
				//της 10x10 περιοχης
					break;
				}else{
					cout<<"\nPLEASE INSERT A VALID Y POSITION"<<endl;
				}			
				
			}		
		
			while(true){//Εδω ζητουνται οι δαστασεις απο τον χρηστη
	
				cout<<"\nINSERT THE DIMENSIONS OF THE SQUARE REGION (BETWEEN 1-10):";
				while(!(cin>>squaredimensions)){
					cin.clear(); 
    				cin.ignore(INT_MAX, '\n'); 
    				cout<<"\nPLEASE INSERT VALID DIMENSIONS"<<endl;
    				cout<<"\nINSERT THE DIMENSIONS OF THE SQUARE REGION (BETWEEN 1-10):";
				}
				if(squaredimensions>=1&&squaredimensions<=10){//Oι διαστασεις πρεπει να ειναι απο 1x1 μεχρι και 10x10
					break;
				}else{
					cout<<"\nPLEASE INSERT VALID DIMENSIONS"<<endl;
				}		
				
			}		
	
			if((squarelowerlefttcornerx+squaredimensions)<=10 && (squarelowerlefttcornery+squaredimensions)<=10){//Στο τελος με τα δεδομενα που εδωσε ο χρηστης για 
			//την περιοχη που θελει εξεταζεται αν αυτη ειναι εντος των οριων της 10x10
				cout<<"\nYOUR SQUARE REGION HAS BEEN CREATED!"<<endl;
				cout<<"\nDIMENSIONS: "<<squaredimensions<<endl;
				cout<<"\nLOWER LEFT X: "<<squarelowerlefttcornerx<<endl;
				cout<<"\nLOWER LEFT Y: "<<squarelowerlefttcornery<<endl;
				break;
			}else{
				cout<<"\nYOUR SQUARE'S DIMENSIONS ARE OUT OF BORDER.PLEASE TRY AGAIN"<<endl;//Αν δεν ειναι, ζητουνται ξανα χ,y και διαστασεις
			}		
			
		
		}	
	

		for(int i=0; i<=13; i++){
			FIND_CROWDED_PLACES(d, i, timeinterval, squaredimensions, squarelowerlefttcornerx, squarelowerlefttcornery, minimumstay);
		}//Παιρνει ως ορισματα αυτα του χρηστη και μετραει τους χρηστες 	

		cout<<"\nUSERS DETECTED WHO STAYED FOR "<<minimumstay<<" SECONDS INTO THE GIVEN SQUARE REGION FOR A PERIOD OF "<<timeinterval<<" SECONDS: "<<users<<"\n"<<endl;
		//Εμφανιζει τα αποτελεσματα
	
	}


}

