import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Vertax implements Comparable<Vertax> {
    private int cost, st, end;

    public Vertax(int cost, int st, int end) {
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
    public int compareTo(Vertax other) {
        if (this.cost < other.cost)
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

    public static void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }

    public static boolean isUnion(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return true;
        else
            return false;
    }

    public static int n, m;
    public static int[] parent;
    public static PriorityQueue<Vertax> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            pq.add(new Vertax(z, x, y));
        }

        int res = 0;
        while (!pq.isEmpty()) {
            Vertax now = pq.poll();
            int x = now.getSt();
            int y = now.getEnd();
            if (isUnion(x, y))
                continue;
            res += now.getCost();
            merge(x, y);
        }
        System.out.println(res);
    }
}
