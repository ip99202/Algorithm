import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Node1 implements Comparable<Node1> {
    private int cost, st, end;

    public Node1(int cost, int st, int end) {
        this.cost = cost;
        this.st = st;
        this.end = end;
    }

    public int getCost() {
        return cost;
    }

    public int getSt() {
        return st;
    }

    public int getEnd() {
        return end;
    }

    @Override
    public int compareTo(Node1 o) {
        if (this.cost < o.cost)
            return -1;
        return 1;
    }
}

public class Main {

    public static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y) {
        x = find(x);
        y = find(y);
        parent[y] = x;
    }

    public static boolean isUnoin(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return true;
        return false;
    }

    public static int n, m;
    public static int[] parent;
    public static PriorityQueue<Node1> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            pq.add(new Node1(c, a, b));
        }

        int res = 0, sum = 0;
        while (!pq.isEmpty()) {
            Node1 now = pq.poll();
            int x = now.getSt();
            int y = now.getEnd();
            if (!isUnoin(x, y)) {
                res = now.getCost();
                sum += now.getCost();
                union(x, y);
            }
        }
        System.out.println(sum - res);
        br.close();
    }
}