import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

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

public class Main {

    public static int n, m, k, x;
    public static ArrayList<ArrayList<Node>> arr = new ArrayList<ArrayList<Node>>();
    public static PriorityQueue<Node> pq = new PriorityQueue<Node>();
    public static int[] res;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        res = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<Node>());
            res[i] = (int) 1e9;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr.get(a).add(new Node(b, c));
            arr.get(b).add(new Node(a, c));
        }

        pq.add(new Node(1, 0));
        res[1] = 0;
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int cost = node.getCost();
            int now = node.getIndex();
            if (res[now] < cost)
                continue;
            for (int i = 0; i < arr.get(now).size(); i++) {
                int nCost = res[now] + arr.get(now).get(i).getCost();
                if (nCost < res[arr.get(now).get(i).getIndex()]) {
                    res[arr.get(now).get(i).getIndex()] = nCost;
                    pq.add(new Node(arr.get(now).get(i).getIndex(), nCost));
                }
            }
        }
        System.out.println(res[n]);
        br.close();
    }
}
