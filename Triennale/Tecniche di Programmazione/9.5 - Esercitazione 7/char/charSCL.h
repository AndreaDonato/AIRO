typedef char SCL_Type;
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
// Conversion to char*
char *constcharstar_to_charstar(const char *mystring);

/********************************************************
*    INFO FOR THESE FUNCTIONS CAN BE FOUND IN SCL.H     *
********************************************************/
bool SCL_is_empty(SCL_Pointer scl_p);

void SCL_Copy(SCL_Pointer scl_p, SCL_Pointer *ris);

void SCL_Delete(SCL_Pointer *scl_p);

void SCL_Add_Node(SCL_Pointer *scl_p, SCL_Type x, int n);

void SCL_Delete_Node(SCL_Pointer *scl_p, int n);

bool SCL_Same_Size(SCL_Pointer scl1_p, SCL_Pointer scl2_p);

void reverse(SCL_Pointer to_reverse, SCL_Pointer *reversed);

void SCL_Inverter(SCL_Pointer scl_p);

int SCL_Length(SCL_Pointer scl_p);

/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/

//// Funzione di supporto a SCL_String_Print
void printing(SCL_Pointer s);

// 7.7
void SCL_String_Print(SCL_Pointer s);

// 7.8
void SCL_String_Create(const char *s, SCL_Pointer *ris);

// 7.9
bool SCL_String_is_equal(SCL_Pointer scl_p, const char *s);

// 7.10
void SCL_String_Remove(SCL_Pointer *scl_p, char val);
