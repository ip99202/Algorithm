import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Node implements Comparable<Node> {
    private int index;
    private int distance;

    public Node(int index, int distance) {
        this.index = index;
        this.distance = distance;
    }

    public int getIndex() {
        return index;
    }

    public int getDistance() {
        return distance;
    }

    @Override
    public int compareTo(Node other) {
        if (this.distance < other.distance)
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
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        res = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<Node>());
            res[i] = (int) 1e9;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(new Node(b, 1));
        }

        pq.add(new Node(x, 0));
        res[x] = 0;
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int dist = node.getDistance();
            int now = node.getIndex();
            if (res[now] < dist)
                continue;
            for (int i = 0; i < arr.get(now).size(); i++) {
                int cost = res[now] + arr.get(now).get(i).getDistance();
                if (cost < res[arr.get(now).get(i).getIndex()]) {
                    res[arr.get(now).get(i).getIndex()] = cost;
                    pq.add(new Node(arr.get(now).get(i).getIndex(), cost));
                }
            }
        }

        boolean flag = false;
        for (int i = 1; i <= n; i++) {
            if (res[i] == k) {
                flag = true;
                System.out.println(i);
            }
        }
        if (!flag)
            System.out.println(-1);
        br.close();
    }
}
