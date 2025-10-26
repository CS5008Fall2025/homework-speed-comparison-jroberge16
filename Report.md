# Report for Data Structure Speed Comparison Homework

Make sure to answer every question in this homework. You should not bullet point your answers, but
instead write them as a full report format. This doesn't mean you have to be wordy, as concise is good,
but it does mean you need to use proper grammar, spelling, and be complete. For question that just
ask for a short answer, answer accordingly. Make sure to include references where appropriate.

## Algorithmic Analysis - Big $O$

Complete the Big O table below for the following functions. You may use any resource you like, but
for the SortedVector and SortedList, you should use the Big O for the functions you wrote in the
the homework. Both Single and Double Linked List you can assume head and tail pointers are available. 
Don't forget to use latex math notation (example in the table).

### Big $O$ Table

| -                         | Add/Insert | Remove | Search/Find | Sort   | Add Front | Add Back | Remove Front | Remove Back | Get by Index |
| ------------------------- |:----------:|:------:|:-----------:|:------:|:---------:|:--------:|:------------:|:-----------:|:------------:|
| Vector                    | $O(n)$     | $O(n)$ |    $O(n)$   |    $n \cdot log(n)$    |$O(n)$| amortized $O(1)$, worst $O(n)$|   $O(n)$    |    $O(1)$   |    $O(1)$    |
| Single Linked List        | $O(n)$     | $O(n)$ |    $O(n)$   |  $n \cdot log(n)$       | $O(1)$    |   $O(1)$ |    $O(1)$    |   $O(n)$    |    $O(n)$    |
| Double Linked List        | $O(n)$     | $O(n)$ |   $O(n)$    |  $n \cdot log(n)$       | $O(1)$    | $O(1)$   |  $O(1)$      |   $O(1)$    |   $O(n)$     |
| Sorted Vector             | $O(n)$     | $O(n)$ |  $log(n)$   | $O(1)$ | ---       | ---      | ---          | ---         | ---          |
| Sorted Single Linked List | $O(n)$     | $O(n)$ |  $O(n)$     | $O(1)$ | ---       | ---      | ---          | ---         | ---          |
| Sorted Double Linked List | $O(n)$     | $O(n)$ | $O(n)$      | $O(1)$ | ---       | ---      | ---          | ---         | ---          |
| Binary Search Tree        |  amortized $O(log(n))$, worst $O(n)$  | amortized $O(log(n))$, worst $O(n)$ | amortized $O(log(n))$, worst $O(n)$ | $O(n)$ | ---       | ---      | ---          | ---         | ---          |

For Sort, we are asking for the Big $O$ for taking the current data structure and writing it 'sorted' to a file. However, not the file writes. For example, if you have a vector of 1000 elements, and you want to write it to a file, you would need to sort it first. So, the Big $O$ for this would be the Big $O$ for sorting. For BST, you have to convert the tree to a sequential structure, so the cost of doing that.  

### Assumptions with Sort

Since the worst case can change considerably based on what sort you use for sorting (if any), list each algorithm below, and specify the algorithm used in your assumption.  For BST, write which  method of traversal you would use to sort it.  

* Vector: We can assume that we can write these values in $n \cdot log(n)$ using the merge sort algorithm.
* Single Linked List: We can assume that we can write these values in $n \cdot log(n)$ using the merge sort algorithm. We can implement Merge sort on a linked list directly, or we can convert a linked list to an array and back again in $O(n)$.
* Double Linked List: We can assume that we can write these values in $n \cdot log(n)$ using the merge sort algorithm. We can implement Merge sort on a linked list directly, or we can convert a linked list to an array and back again in $O(n)$.
* Sorted Vector - already sorted
* Sorted Single Linked List - already sorted: $O(n)$ since we are writing to a file
* Sorted Double Linked List - already sorted: $O(n)$ since we are writing to a file
* Binary Search Tree: We can assume in order traversal. `BST` trees are already in order, so the cost here is writing to a file, which would be $O(n)$.

source:https://www.youtube.com/watch?v=8ocB7a_c-Cc


### Worst Case vs. Average Case

There are a few functions whose worse case is very different than the average case. Name at least two of them, and explain why the worse case is so much worse than the average case. 

1. Binary Search Tree: 
   For the Operations `Add/Insert`, `Search/Find`, and `Remove`, we have different runtimes depending on whether we are looking at amortized or not amortized. This is due to the structure  and make up of Tree before these operations take place. If we are given data that is already ordered, then we will essentially be creating a linked list. In this scenario we inherit the runtime of the linked list, but if our data is randomized then we can assume amortized case. Here is an example of our worst case, lets say we are add the following values to our tree one at a time: 10,9,8,7, and 6 the resulting tree would be as follows:
   
   ```mermaid
   flowchart TD
      10 --> 9
      9 --> 8
      8 --> 7
      7 --> 6
   ```
2. Vector:
   In out add to the back operation for our vector data structure, we have run amortized runtime of $O(1)$ vs a worst case of $O(n)$. This worst case happens when we go over capacity for our vector. Our vector is a fixed size, and when we reach that fixed size we make a new array that is generally double the capacity. With this new array we then copy the existing values from the old array into the new array. When this happens, our worst case is $O(n)$, but generally adding to the back is $O(1)$.



## Empirical Analysis - Speed Comparison

For this section, you will need to have run the speed compare program and generated the output into a CSV file.

### Empirical Results Table

Add a link from this document to the CSV file you generated. The CSV file must have at least 15 different N values, but
often can have a lot more depending on what you ran.  

### Analysis

Create *at least three* graphics that each visually explain an aspect of your data related to an operation or data structure. Under each one, explain what the graphic is showing, and what you can conclude from it/what you find interesting about it.

> [!IMPORTANT]
> 
> Make sure you are comparing apples to apples and not apples to oranges when choosing what to put in the same graph. 
> 
> **:x: different data structures *and* different operations**
> 
> - Vector Add Front versus BST Add
> 
> **:white_check_mark: different operations *but* same data structure**
> 
> - BST Add versus Remove, and Search for BST
> 
> **:white_check_mark: different data structures *but* same operation**
> 
> - BST Add versus Add for Sorted Vector, and Sorted Single/Double Linked List
> 
> - Vector Add Front versus Add Front for Single/Double Linked List

> [!TIP]
> 
> To create the graphics you can use a third party program like Microsoft Excel or Google Sheets. (Completely optional if you want extra coding: you can use python libraries such as matplotlib, seaborn, or plotly)
> 
> Make sure you can see the image embedded in the Report.md using [image markdown] when you upload it to github, and get help if it doesn't show! 

#### Graphic 1 (Replace with a descriptive title)

<div align="center">
  ![Image alt text]("data analysis/images/operation_v_Time.png")
</div>


#### Graphic 2 (Replace with a descriptive title)

  ![Image alt text]("data analysis\images\operation_v_Time.png")

#### Graphic 3 (Replace with a descriptive title)

> Insert your comments/observations about the graphic here

## Critical Thought

### Data Evaluation

Answer the questions below. Make sure to answer each question fully, and explain your reasoning. Indent your answers immediately below the question, for it to line up with the bullet point.

For example:

```markdown
1. What is the most surprising result from the data? Why is it surprising?
   Answer here
```

1. What is the most surprising result from the data? Why is it surprising?

2. What data structure is the fast at adding elements (sorted)? Why do you think that is?

3. What data structure is the fastest at removing elements (sorted)? Why do you think that is?

4. What data structure is the fastest at searching? Why do you think that is?

5. What data structure is the fastest for adding elements to the front? Why do you think that is?

6. What data structure is the fastest for adding elements to the back? Why do you think that is?

7. What data structure is the fastest for removing elements from the front? Why do you think that is?

8. What data structure is the fastest for removing elements from the back? Why do you think that is?

### Deeper Thinking

#### Double Linked List vs Single Linked List

1. If you wrote your linked list as a single linked list, removing from the back was expensive. If you wrote it as a double linked list, removing from the back was cheap. Why do you think that is?

With a doubly linked list we can traverse our dataset forward and backward, while a singly linked list we can traverse in the forward direction. Although we can access the last element of a singly linked list in $O(1)$ time, we cannot reassign the $(n-1)$ value as the last value without traversing the entire data structure. With a doubly linked list, removing the last element is trivial because we can go to the last element, then go to its previous node, assign it as the last value, and then remove the node. Given this information, removing the last node in a singly linked list has a time complexity of $O(n)$, while a doubly linked list’s time is $O(1)$.

2. When running most functions, at least ~30% of the tests were worse case scenarios. Why do you think that is?

Our sampling method for our datasets ensures that at least 30% of our searches and removals are based on a worst-case scenario. This is because 30% of our samples are not present in our samples, which means we have to search through every node before returning NULL.

3. What was done in the code to encourage that?

The function ` build_sample_indexes` suggests that 30% of our removals and searches are a worst-case scenario. In this function, the variable `SAMPLE_SPLIT` builds our experiment so that 70% of the samples will exist in the linked list while the 30% of the samples may or may not exist. Therefore, we are forced to traverse all nodes in order to determine that a value is not present in our linked list. 

4. How did this particularly influence the linked list searches?
```mermaid
flowchart LR
    node_1["Head<br/>Node 1<br/>value: 1"] --> node_2["Node 2<br/>value: 2"]
    node_2 --> node_3["Node 3<br/>value: 3"]
    node_3 --> Null((Null))
```
The chart above shows us a basic singly linked list. Lets say we are trying to find the value $4$ in this linked list.To find the value $4$, we must traverse the entire data structure. This scenario is particularly bad for a linked list because other data structures can use sort order to alleviate this shortcoming. In a sorted vector, we can use binary search ($O(\log(n))$), and with a binary search tree, our amortized search is $O(\log(n))$. A linked list really does not have a mechanism to take advantage of ordering and therefore must check every node.

#### Test Bias

1. The tests were inherently biased towards the BST to perform better due the setup of the experiment. Explain why this is the case.  (hint: think about the randomization of the data, and the worst case scenario for BST).

In our experiment, we are taking random samples, and BST performs best with randomized data. When data is randomized, it is likely that we will end up building a relatively balanced tree. A tree is considered balanced when the height of the tree is no greater than $O(\log(n))$. When a binary tree has this property, it means that our add, delete, find, and remove operations will be $O(\log(n))$.

https://www.geeksforgeeks.org/dsa/balanced-binary-tree/

2. What would generate the worst case scenery for a BST?

 ```mermaid
   flowchart TD
      10 --> 9
      9 --> 8
      8 --> 7
      7 --> 6
   ```

The worst-case scenario for a BST happens when our data is already ordered. The diagram above shows us trying to build a tree based on the values [10, 9, 8, 7, 6]. Because the values are already in order, we essentially end up building a linked list and thus inherit all the properties of a linked list.


3. Researching beyond the module, how would one fix a BST so the worst case scenario matches (or at least i closer to) the average case.[^1^]

We can alleviate this shortcoming of binary search trees by implementing a  tree data structure that self balances. There are two common  data structures that self-balance: AVL trees and Red-Black trees. Because these data structures self-balance, we maintain the property of a balanced tree when we insert new values. Let’s dive deeper into an AVL tree.

An AVL tree is one of our self-balancing trees. AVL's are able to maintain its balance by keeping track of each nodes Balance Factor ($B_f$). $B_f$ is calculated by subtracting the height of the left subtree from the height of the right subtree ($B_f = H_l - H_r$). $B_f $ value is greater than 1, we perform a rotations that will move nodes around until we regain our balance property. There are four different types of rotations that an AVL tree can implement in order to regain the balance factor, and they are as follows:

* Left-Left (LL) Rotation
* Right-Right (RR) Rotation
* Left-Right (LR) Rotation
* Right-Left (RL) Rotation

https://www.geeksforgeeks.org/dsa/self-balancing-binary-search-trees/
https://www.youtube.com/watch?v=zP2xbKerIds
https://www.geeksforgeeks.org/dsa/introduction-to-avl-tree/

## Scenario

Fill out the table below. This is a common technical interview topic!

| Structure          | Good to use when                                                                 | Bad to use when                                                                  |
| ------------------ | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| Vector             |                                                                                  |                                                                                  |
| Linked List        | Good for stacks with frequent front only access                                  |                                                                                  |
| Sorted Vector      | When values coming in are already mostly sorted and we need quick search access. | When space is limited and the dataset is extremely large causing memory to swap. |
| Sorted Linked List |                                                                                  |                                                                                  |
| BST                |                                                                                  | data is presorted                                                                |

## Conclusion

Summarize your findings. Where there any surprises?  What did you end up learning by comparing speeds?

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

## References

Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

[1] Reference info, date, etc.

[^1^]: Implementing a BST with a self-balancing algorithm, such as AVL or Red-Black Trees is a great research paper topic!

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->

[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
