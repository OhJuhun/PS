
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0,nullptr);
		ListNode* pt = head;

        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l1->val<=l2->val){
            head->val = l1->val;
            l1 = l1->next;
        }
        else{
            head->val = l2->val;
            l2 = l2->next;
        }
        
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                pt->next = l1;
                l1=l1->next;
            }
            else{
                pt->next =l2;
                l2=l2->next;
            }
            pt=pt->next;
        }
        if(l1!=nullptr) pt->next = l1;
        if(l2!=nullptr) pt->next = l2;
		return head;
    }
};