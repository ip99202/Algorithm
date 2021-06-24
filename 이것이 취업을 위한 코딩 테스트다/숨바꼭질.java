import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.*;

class Node implements Comparable<Node> {
    private int index;
    private int cost;

    public Node(int index, int cost) {
        this.index = index;
        this.cost = cost;
    }

    public int getIndex() {
        return index;
    }

    public int getCost() {
        return cost;
    }

    @Override
    public int compareTo(Node other) {
        if (this.cost < other.cost)
            return -1;
        return 1;
    }
}

class Pair {
    private int index, cnt;

    public Pair(int index, int cnt) {
        this.index = index;
        this.cnt = cnt;
    }

    public int getIndex() {
        return index;
    }

    public int getCnt() {
        return cnt;
    }
}

public class Main {
    public static void bfs() {
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int now = node.getIndex();
            for (int i = 0; i < arr.get(now).size(); i++) {
                int next = arr.get(now).get(i);
                if (visited[next] == 1)
                    continue;
                visited[next] = 1;
                pq.add(new Node(next, node.getCost() + 1));
                if (res.get(node.getCost() + 1) == null) {
                    res.put(node.getCost() + 1, new Pair(next, 1));
                } else {
                    int index = next;
                    int cnt = res.get(node.getCost() + 1).getCnt() + 1;
                    if(index > res.get(node.getCost() + 1).getIndex())
                        index = res.get(node.getCost() + 1).getIndex();
                    res.replace(node.getCost() + 1, new Pair(index, cnt));
                }
            }
        }
    }

    public static int n, m;
    public static int[] visited;
    public static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public static PriorityQueue<Node> pq = new PriorityQueue<>();
    public static Map<Integer, Pair> res = new HashMap<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = parseInt(st.nextToken());
        m = parseInt(st.nextToken());
        visited = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = parseInt(st.nextToken());
            int b = parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
        }
        pq.add(new Node(1, 0));
        visited[1] = 1;
        bfs();
        int dis = 0, index = 0, cnt = 0;
        for (Map.Entry<Integer, Pair> entry : res.entrySet()) {
            if (dis < entry.getKey()) {
                index = entry.getValue().getIndex();
                cnt = entry.getValue().getCnt();
                dis = entry.getKey();
            }
        }
        System.out.println(index + " " + dis + " " + cnt);
        br.close();
    }
}
