typedef float SCL_Type;
struct SCL_Element
{
	SCL_Type info;
	struct SCL_Element *next;				// SCL_Pointer next;
};

	typedef struct SCL_Element SCL_Node;
	typedef SCL_Element* SCL_Pointer;

/********************************************************
*               AUSILIARY FUNCTIONS                     *
********************************************************/
// Funzione side-effect che aggiunge un nodo in prima posizione a una SCL
void SCL_Add_First_Node(SCL_Pointer *p, SCL_Type x);

// Funzione side-effect che elimina il nodo in prima posizione di una SCL
void SCL_Delete_First_Node(SCL_Pointer *scl_p);

// Restituisce true se la SCL passata è vuota
bool SCL_is_empty(SCL_Node scl);

// Cerca un elemento di valore x nella SCL puntata da scl_p, mettendo in ris il puntatore al nodo (NULL se non c'è)
void SCL_Find_Element(SCL_Pointer scl_p, SCL_Type x, SCL_Pointer *ris);

// Crea una SCL di n elementi aventi valore x
void SCL_Uniform_Fill(SCL_Pointer *scl_p, int n, SCL_Type x);

////// Funzione di supporto a Recursive_Random_Fill;
float Random_Float();

//// Funzione di supporto a SCL_Random_Fill per inizializzare una sola volta srand
void Recursive_Random_Fill(SCL_Pointer *scl_p, int n);

// Crea una SCL di n elementi con valori casuali
void SCL_Random_Fill(SCL_Pointer *scl_p, int n);

// Copia la SCL puntata da scl_p nella posizione puntata da ris
void SCL_Copy(SCL_Pointer scl_p, SCL_Pointer *ris);

// Elimina la SCL puntata da scl_p
void SCL_Delete(SCL_Pointer *scl_p);

// Inserisce un nodo in posizione n
void SCL_Add_Node(SCL_Pointer *scl_p, SCL_Type x, int n);

// Elimina un nodo in posizione n
void SCL_Delete_Node(SCL_Pointer *scl_p, int n);

//// Funzione di supporto a SCL_Print
void fileprint(SCL_Pointer scl_p, FILE *fp);

// Stampa su file o su stdout il contenuto di una SCL
void SCL_Print(SCL_Pointer scl_p, const char *filename);

// Restituisce true se le due SCL hanno lo stesso numero di elementi, falso altrimenti
bool SCL_Same_Size(SCL_Pointer scl1_p, SCL_Pointer scl2_p);

//// Funzione di supporto a SCL_Inverter
void reverse(SCL_Pointer to_reverse, SCL_Pointer *reversed);

// Inverte l'ordine degli elementi di una SCL
void SCL_Inverter(SCL_Pointer scl_p);

/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/

// 7.1
int SCL_Length(SCL_Pointer scl_p);

// 7.2
float SCL_Sum(SCL_Pointer scl_p);

// 7.3
float SCL_Mean(SCL_Pointer scl_p);

// 7.4
float SCL_Dot(SCL_Pointer scl1_p, SCL_Pointer scl2_p);

// 7.5
void SCL_Duplicate_Node(SCL_Pointer scl_p, int pos);

// 7.6
void SCL_Positives(SCL_Pointer scl_p, SCL_Pointer *ris);