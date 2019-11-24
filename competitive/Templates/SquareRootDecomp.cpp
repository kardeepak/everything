class SQRTDecomposition {
	LL n, sn;
	LL *arr, *sqarr;
public:
	SQRTDecomposition(LL n) {
		this->n = n;
		sn = (LL)ceil(sqrt(n));
		arr = new LL[n];
		sqarr = new LL[sn];
		memset(arr, 0, sizeof(arr));
		memset(sqarr, 0, sizeof(sqarr));
	}
	void update(LL index, LL value) {
		LL sqindex = (index / sn);
		sqarr[sqindex] += (value - arr[index]);
		arr[index] = value;
	}
	LL get(LL index) {
		return arr[index];
	}
	LL getSum(LL left, LL right) {
		LL sum = 0;
		while(left%sn != 0 && left <= right)	sum += arr[left++];
		while(right%sn != sn-1 && left <= right)	sum += arr[right--];
		while(left <= right) {
			sum += sqarr[left/sn];
			left += sn;
		}
		return sum;
	}
}