public final class MatrixPathFinder {
	
	private int [][] grid;
	private int [][] path;
	private int numRows;
	private int numCols;
	
	public MatrixPathFinder(int[][] mat, int M, int N) {
		this.grid = mat; //new Integer[M][N];
		this.path = new int[M][N];
		
		this.numRows =  M;
		this.numCols = N;
	}
	
	public void addOne() {
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < numCols; ++j) {
				grid[i][j] += 1;
			}
		}
	}
	
	public int findNumOfPaths() {
		initialize();
		
		for (int i = 1; i < numRows; ++i) {
			for (int j = 1; j < numCols; ++j) {
				if (grid[i][j] == 0) {
					path[i][j] = 0;
					continue;
				}
				path[i][j] = path[i][j-1] + path[i-1][j];
			}
		}
		return path[numRows-1][numCols-1];
	}

	private void initialize() {
		
		boolean zeroFound = false;
		for(int i = 0; i < numCols; ++i) {
			zeroFound = grid[0][i] == 0 || zeroFound ? true : false;
			path[0][i] = zeroFound ? 0 : 1;
			
		}
		
		zeroFound = false;
		for(int i = 0; i < numRows; ++i) {
			zeroFound = grid[i][0] == 0 || zeroFound ? true : false;
			path[i][0] = zeroFound ? 0 : 1;  
		}
		
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < numCols; ++j) {
				System.out.print(path[i][j]+ " ");
			}
			System.out.println("");
		}
	}
	
	public static void driver() {
		int [][] grid = {{1,1,1},{1,1,1},{1,0,1}};
		MatrixPathFinder pf = new MatrixPathFinder(grid.clone(), 3, 3);
		//pf.addOne();
		//pf.addOne();
		
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				System.out.print(grid[i][j]+ " ");
			}
			System.out.println("");
		}
		
		System.out.println(pf.findNumOfPaths());
	
	}

}
