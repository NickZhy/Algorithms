class Solution {
    boolean dfs(int course, List<List<Integer>> graph, int[] visited) {
        if(visited[course] == -1) return false;
        if(visited[course] ==  1) return true;
        visited[course] = -1;
        for(int dep: graph.get(course)) {
            if(!dfs(dep, graph, visited))
                return false;
        }
        visited[course] = 1;
        return true;
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<List<Integer>>();
        for(int i = 0; i < numCourses; ++i)
            graph.add(new ArrayList<Integer>());
        boolean[] hasDep = new boolean[numCourses];
        for(int[] edge: prerequisites) {
            int s = edge[0], t = edge[1];
            if(graph.get(s) == null)
                graph.set(s, new ArrayList<Integer>());
            graph.get(s).add(t);
            hasDep[t] = true;
        }
        int[] visited = new int[numCourses];
        for(int i = 0; i < numCourses; ++i) {
            if(visited[i] == 0 && !hasDep[i]) {
                if(!dfs(i, graph, visited)) 
                    return false;
            }
        }
        for(int i = 0; i < numCourses; ++i) {
            if(visited[i] == 0) return false;
        }
        return true;
    }
}