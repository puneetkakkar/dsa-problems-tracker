# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # If both the lists are empty then, return empty list
        if list1 == None and list2 == None:
            return list1

        # If any one of the lists is empty, then return the non-empty list
        if list1 == None:
            return list2
        elif list2 == None:
            return list1

        # If the lengths of the lists are same, then compare both the linked
        # list simultaneously to merge them into a single list.
        result_list = ListNode()
        new_list = result_list
        while list1 != None and list2 != None:
            if list1.val <= list2.val:
                new_list.next = list1
                list1 = list1.next
            else:
                new_list.next = list2
                list2 = list2.next

            new_list = new_list.next

        # Check if list1 has still not reached its end, then point the last of new_list to list1
        if list1 is not None:
            new_list.next = list1

        # Check if list2 has still not reached its end, then point the last of the new_list to list2
        if list2 is not None:
            new_list.next = list2

        return result_list.next
