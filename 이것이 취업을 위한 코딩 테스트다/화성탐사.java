import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node> {
    int x, y, sum;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getSum() {
        return sum;
    }

    public Node(int x, int y, int sum) {
        this.x = x;
        this.y = y;
        this.sum = sum;
    }

    @Override
    public int compareTo(Node o) {
        if (this.sum > o.sum)
            return 1;
        else
            return -1;
    }
}

public class Main {

    public static int bfs() {
        while (!pq.isEmpty()) {
            Node now = pq.poll();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + now.getX();
                int ny = dy[i] + now.getY();
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (nx == n - 1 && ny == n - 1) {
                    return now.getSum() + arr[nx][ny];
                }
                pq.add(new Node(nx, ny, now.getSum() + arr[nx][ny]));
            }
        }
        return -1;
    }

    public static int n, t;
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};
    public static int[][] arr;
    public static PriorityQueue<Node> pq = new PriorityQueue<Node>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        t = Integer.parseInt(st.nextToken());
        for (int k = 0; k < t; k++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            arr = new int[n][n];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            pq.add(new Node(0, 0, arr[0][0]));
            System.out.println(bfs());
            pq.clear();
        }
        br.close();
    }
}
