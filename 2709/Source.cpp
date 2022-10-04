#include <iostream>

using namespace std;

class List {
public:
	List();
	~List();
	 
private:
	char text;
	int count;
};

 

template <class T> class Node//стрyктyра

{

public:

    T v;

    Node<T>* next;

    Node<T>* previos;



    Node()

    {

        previos = next = NULL;

    }

    Node(T val)

    {

        previos = next = NULL;

        v = val;

    }

    Node(const Node* nod)

    {

        v = nod->v;

        next = nod->next;

        previos = nod->previos;

    }

    template <class T> class Iterator

    {

    private:

        Node<T>* node;



    public:

        Iterator() { node = NULL; }

        Iterator(Node<T>* nod)

        {

            node = nod;

        }

        Iterator<T> operator++ ()

        {

            node = node->next;

            return *this;

        }

        Iterator<T> operator-- ()

        {

            node = node->previos;

            return *this;

        }

        Iterator<T> operator= (const Iterator<T>& it)

        {

            node = it.node;

            return *this;

        }



        Iterator<T> operator+ (int di)

        {

            Iterator<T> temp;

            temp.node = node;

            for (int i = 1; i < di; i++)

            {

                ++temp;

            }

            return temp;

        }

        Iterator<T> operator- (int di)

        {

            Iterator<T> temp;

            temp.node = node;

            for (int i = 1; i < di; i++)

            {

                --temp;

            }

            return temp;

        }



        void setNode(Node<T>* nod)

        {

            node = nod;

        }



        Node<T>* getNode()

        {

            return node;

        }



        T value()

        {

            return node->v;

        }

    };

    template <class T> class List

    {

    private:

        Node<T>* frontNode;  

        Node<T>* backNode;   



    public:

        List()

        {

            frontNode = NULL;

            backNode = NULL;

        }

        ~List()

        {

            while (1)

            {

                Node<T>* temp;



               


                if (frontNode == NULL)

                    return;

                if (frontNode == backNode)

                {

                    delete frontNode;

                    return;

                }

                temp = backNode->previos;

                delete backNode;

                backNode = temp;

            }

        }



      

        void pushBack(T val)

        {

            if (frontNode == NULL)  

            {

                frontNode = new Node<T>(val);

                backNode = frontNode;

                backNode->previos = frontNode;

                frontNode->next = backNode;

                backNode->next = NULL;

            }

            else

            {

                Node<T>* temp = backNode;  

                backNode = new Node<T>(val);

                temp->next = backNode;

                backNode->previos = temp;

                backNode->next = NULL;

            }

        }



        

        void pushFront(T val)

        {

            if (frontNode == NULL)  

            {

                frontNode = new Node<T>(val);

                backNode = frontNode;

                backNode->previos = frontNode;

                frontNode->next = backNode;

                backNode->next = NULL;

            }

            else

            {

                Node<T>* temp = frontNode;  

                frontNode = new Node<T>(val);

                temp->previos = frontNode;

                frontNode->next = temp;

                frontNode->previos = NULL;

            }

        }

        void popBack()

        {

            if (frontNode == NULL)  

                return;  

            if (backNode == NULL)  

            {

                delete frontNode;  

                frontNode = NULL;

                return;

            }

            Node<T>* temp = backNode;  

            backNode = temp->previos;

            delete temp;

            backNode->next = NULL;

        }



        

        void popFront()

        {

            if (frontNode == NULL) 

                return;  

            if (backNode == NULL)  

            {

                delete frontNode;  

                frontNode = NULL;

                return;

            }

            Node<T>* temp;

            temp = frontNode;  

            frontNode = frontNode->next;

            delete temp;

            frontNode->previos = NULL;

        }



         

         

        void isert(T val, Iterator<T> itr)

        {

            Node<T>* temp;

            if (itr.getNode()->next == NULL)  

            {

                temp = backNode;

                backNode = new Node<T>(val);

                temp->next = backNode;

                backNode->previos = temp;

                return;

            }

            temp = itr.getNode()->next;

            Node<T>* insertNode = new Node<T>(val);

            itr.getNode()->next = insertNode;

            insertNode->previos = itr.getNode();

            insertNode->next = temp;

            temp->previos = insertNode;

        }



         

        Iterator<T> begin()

        {

            Iterator<T> it(frontNode);

            return it;

        }



         

        Iterator<T> end()

        {

            Iterator<T> it(backNode);

            return it;

        }



         

        int size()

        {

            int count = 0;

            Node<T>* temp = frontNode;

            while (temp != NULL)

            {

                count++;

                temp = temp->next;

            }

            return count;

        }



         

        bool emty()

        {

            if (frontNode == NULL)

                return true;

            return false;

        }



         

        void erase(Iterator<T> itr)

        {

            Node<T>* delNode;

            delNode = itr.getNode();

            if (delNode->next == NULL)  

            {

                popBack();

                return;

            }

            if (delNode->previos == NULL)  

            {

                popFront();

                return;

            }

            Node<T>* n_Node, * p_Node;

            n_Node = delNode->next;

            p_Node = delNode->previos;

            p_Node->next = n_Node;

            n_Node->previos = p_Node;

            delete delNode;

        }



         

        void clear()

        {

            while (1)

            {

                Node<T>* temp;

                if (backNode == frontNode)

                {

                    delete frontNode;

                    backNode = NULL;

                    frontNode = NULL;

                    return;

                }

                temp = backNode->previos;

                delete backNode;

                backNode = temp;

            }

        }

    };

    int main()

    {

        List<char> list0;  



        cout << "list0.emty: " << list0.emty() << endl;  

        cout << "list0.size: " << list0.size() << endl << endl;   



         

        list0.pushBack('a');

        list0.pushBack('b');

        list0.pushBack('c');

        list0.pushBack('d');

         

        list0.pushFront('A');

        list0.pushFront('B');

        list0.pushFront('C');



        cout << "list0.emty: " << list0.emty() << endl;  

        cout << "list0.size: " << list0.size() << endl << endl;   



      

        Iterator<char> itr;  

        itr = list0.begin();  

        for (int i = 0; i < list0.size(); i++)

        {

            char ch;



            ch = itr.value();

            cout << ch << ' ';



            ++itr;

        }

        cout << endl << endl;



        cout << "list0.popBack" << endl;

        list0.popBack();  

 

        itr = list0.begin();  

        for (int i = 0; i < list0.size(); i++)

        {

            char ch;



            ch = itr.value();

            cout << ch << ' ';



            ++itr;

        }

        cout << endl << endl;



        cout << "list0.popFront" << endl;

        list0.popFront();  

        itr = list0.begin();  

        for (int i = 0; i < list0.size(); i++)

        {

            char ch;



            ch = itr.value();

            cout << ch << ' ';



            ++itr;

        }

        cout << endl << endl;



         

        itr = list0.begin();  

        cout << "(itr + 3).value: " << (itr + 3).value() << endl << endl;



        

        cout << "list0.isert(T val, Iterator<T> itr)" << endl;

        list0.isert('I', itr + 3);

        itr = list0.begin();  

        for (int i = 0; i < list0.size(); i++)

        {

            char ch;



            ch = itr.value();

            cout << ch << ' ';



            ++itr;

        }

        cout << endl << endl;



       

        cout << "list0.erase: " << endl;

        itr = list0.begin();  

        list0.erase(itr + 4);

        for (int i = 0; i < list0.size(); i++)

        {

            char ch;



            ch = itr.value();

            cout << ch << ' ';



            ++itr;

        }

        cout << endl << endl;





        cout << "list0.clear" << endl;

        list0.clear();

        cout << "list0.emty: " << list0.emty() << endl;

        cout << "list0.size: " << list0.size() << endl << endl;



        return 0;

    }
};