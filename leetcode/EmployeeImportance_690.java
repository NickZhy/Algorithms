/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    int dfs(HashMap<Integer, Employee> mp, int id) {
        Employee e = mp.get(id);
        int totalImportance = e.importance;
        for(int sub: e.subordinates)
            totalImportance += dfs(mp, sub);
        return totalImportance;
    }
    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Employee> mp = new HashMap<Integer, Employee>();
        for(Employee e: employees)
            mp.put(e.id, e);
        return dfs(mp, id);
    }
}