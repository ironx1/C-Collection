# 1.Initalize structures
For example, <br />LinkedList *ll = init_LinkedList();
# 2.Use the object's function pointers
For example, ll->pushBack(ll, pi);<br />
Note that you have to pass pointer to allocated memory from heap to object's function pointers.
# 3.Clear all data with clear function pointer.
For example, ll->clear(ll);

# Function Pointers
pushBack: This function adds an element to the end of a data structure. It expands the size of the structure if necessary and places the new element at the back.<br/>

pushFront: This function adds an element to the front of a data structure. It shifts the existing elements to make room for the new element and places it at the front.<br/>

insert: This function inserts an element at a specified position within a data structure. It adjusts the structure by shifting existing elements to make room for the new element and places it at the desired position.<br/>

popBack: This function removes and returns the element from the end of a data structure. It reduces the size of the structure by one and returns the value of the element that was removed.<br/>

popFront: This function removes and returns the element from the front of a data structure. It adjusts the structure by shifting the remaining elements and returns the value of the element that was removed.<br/>

delete: This function removes a specified element from a data structure. It adjusts the structure by shifting the remaining elements to fill the gap left by the deleted element.<br/>

search: This function searches for a specified element within a data structure and returns either the position/index of the element or a boolean value indicating whether the element is present in the structure.<br/>

getData: This function retrieves the data stored in a specified position within a data structure and returns it.<br/>

clear: This function removes all elements from a data structure, leaving it empty. It resets the size of the structure to zero.<br/>