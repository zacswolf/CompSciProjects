#ifndef BTREE_H
#define BTREE_H

template <size_t D>
class Btree
{
	private :
		Node *root;
		struct Node
		{
			int[D-1] names;
			Node[D] children;
		};
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

#endif // BTREE_H