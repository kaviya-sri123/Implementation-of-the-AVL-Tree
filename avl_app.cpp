#include "avl_header.h"
int main()
{
    int ch;
    int a,tn;
    string n,tc;
    AVL *avl = new AVL();
    TreeNode *root=NULL;
    do
    {
        cout<<"\t==========MENU==========\n";
    	cout<<"\t1.Insert\n";
    	cout<<"\t2.Search\n";
    	cout<<"\t3.First Passenger Details\n";
    	cout<<"\t4.Last Passenger Details\n";
    	cout<<"\t5.Inorder Traversal\n";
    	cout<<"\t6.Preorder Traversal\n";
    	cout<<"\t7.Postorder Traversal\n";
    	cout<<"\t8.Exit\n";
    	cout<<"\t========================\n";
    	cout<<"\nEnter your choice : ";
    	cin>>ch;
        switch(ch)
        {
            case 1:
            	cout<<"\nEnter the Passenger Name : ";
            	cin>>n;
            	cout<<"Enter the Passenger Age : ";
            	cin>>a;
            	cout<<"Enter the ticket number : ";
            	cin>>tn;
            	cout<<"Enter the travelling class : ";
            	cin>>tc;
            	root = avl->insert(root,n,a,tn,tc);
                cout<<"\nPassenger details inserted.\n\n";
            	break;
            case 2:
                int key;
                TreeNode *t;
                cout<<"\nEnter the Ticket Number to search : ";
                cin>>key;
                t = avl->search(root,key);
                if(t == NULL)
                    cout<<"\nPassenger not found.\n\n";
                else
                    cout<<"\nPassenger found.\n\n";
                break;
            case 3:
                TreeNode *minimum;
                minimum = avl->findMin(root);
                if(minimum==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n====FIRST PASSENGER DETAILS====";
                    cout<<"\nName : "<<minimum->name<<endl;
                    cout<<"Age : "<<minimum->age<<endl;
                    cout<<"Ticket Number : "<<minimum->ticket_number<<endl;
                    cout<<"Travel Class : "<<minimum->travel_class<<endl;
                    cout<<"===============================\n\n";
                }
                break;
            case 4:
                TreeNode *maximum;
                maximum = avl->findMax(root);
                if(maximum==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=====LAST PASSENGER DETAILS====";
                    cout<<"\nName : "<<maximum->name<<endl;
                    cout<<"Age : "<<maximum->age<<endl;
                    cout<<"Ticket Number : "<<maximum->ticket_number<<endl;
                    cout<<"Travel Class : "<<maximum->travel_class<<endl;
                    cout<<"===============================\n\n";
                }
                break;
            case 5:
                if(root==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=======PASSENGER DETAILS=======";
                    avl->inorder(root);
                    cout<<"===============================\n\n";
                }
                break;
            case 6:
                if(root==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=======PASSENGER DETAILS=======";
                    avl->preorder(root);
                    cout<<"===============================\n\n";
                }
                break;
            case 7:
                if(root==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=======PASSENGER DETAILS=======";
                    avl->postorder(root);
                    cout<<"===============================\n\n";
                }
                break;
            case 8:
                break;
            default:
                cout<<"\n\nEnter a valid choice.\n";
                break;
        }
    }while(ch != 8);
    return 0;
}