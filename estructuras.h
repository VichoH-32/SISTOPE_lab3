typedef struct _pageTableEntryNode {
	char* PTE[2]; //una entrada es un arreglo de 2 strings. 1:numero de pagina, 2:numero de marco
	struct _pageTableEntryNode* next; 
}PageTableEntryNode;

typedef struct _pageTableEntryList {
	int len;
	PageTableEntryNode* first;
}PageTableEntryList;

typedef struct _pageTable {
	int level; //para saber nivel de PT
	PageTableEntryList entries;
}PageTable;

typedef struct _TLB {
	int entriesCount; //cantidad de entradas de la tlb
	PageTableEntryList entries;
}TLB;