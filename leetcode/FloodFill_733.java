class Solution {
    class Pair {
        int x;
        int y;
        Pair(int xt, int yt) {
            x = xt;
            y = yt;
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        Queue<Pair> q = new ArrayDeque<Pair>();
        q.add(new Pair(sr, sc));
        int color = image[sr][sc];
        if(color == newColor) return image;
        image[sr][sc] = newColor;
        int hei = image.length, wid = image[0].length;
        while(q.size() > 0) {
            Pair curr = q.poll();
            if(curr.x > 0 && image[curr.x - 1][curr.y] == color) {
                image[curr.x - 1][curr.y] = newColor;
                q.add(new Pair(curr.x - 1, curr.y));
            }
            if(curr.y > 0 && image[curr.x][curr.y - 1] == color) {
                image[curr.x][curr.y - 1] = newColor;
                q.add(new Pair(curr.x, curr.y - 1));
            }
            if(curr.x + 1 < hei && image[curr.x + 1][curr.y] == color) {
                image[curr.x + 1][curr.y] = newColor;
                q.add(new Pair(curr.x + 1, curr.y));
            }
            if(curr.y + 1 < wid && image[curr.x][curr.y + 1] == color) {
                image[curr.x][curr.y + 1] = newColor;
                q.add(new Pair(curr.x, curr.y + 1));
            }
        }
        return image;
    }
}