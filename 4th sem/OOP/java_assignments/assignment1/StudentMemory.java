package assng1;

public class StudentMemory
{
	StudentList s1 = new StudentList();
	void eatMemory()
    {
    	int count=s1.getStdCount();
    	int[] intArray = new int[count];

      	for (int i=0; i<count; i++) {
        intArray[i] = i;
    }
}
}