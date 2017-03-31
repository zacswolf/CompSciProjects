//#include "Btree.h"



template <size_t D>
class Btree
{
	private :
		struct Node
		{
			int[D-1] names;
			Node[D] children;
		};
		Node *root;
	public:
		btree();
		void insert (int ins);
		static Node * search (int sea);
		void remove (int rem);
		void clear ();
		static void display ( Node *root );
		static void deltree ( Node *root );
		~btree() ;
};

int main(){
	
	return 0;
}
