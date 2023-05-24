#include <cstdio>


template<int N, int M>
struct comb{
	static const long long result = comb<N-1, M-1>::result + comb<N-1, M>::result;
};

template <int N>
struct comb<N, 0>{
	static const long long result = 1;
};

template <int N>
struct comb<N, N>{
	static const long long result = 1;
};

template <int N, int M>
struct tpow{
	static const long long result = tpow<N, M-1>::result * N;
};

template <int N>
struct tpow<N, 0>{
	static const long long result = 1;
};

template <int N>
struct tpow<N, 1>{
	static const long long result = N;
};

int main(){

	printf("\n");
	long long total = comb<52, 6>::result;
	long long one_pair = comb<13, 1>::result * comb<4, 2>::result * comb<12, 4>::result * tpow<comb<4, 1>::result, 4>::result; //
	long long two_pair = comb<13, 2>::result * tpow<comb<4, 2>::result, 2>::result * comb<11, 2>::result * comb<4, 2>::result; 
	long long triple = comb<13, 1>::result * comb<4, 3>::result * comb<12, 3>::result * tpow<4, 3>::result; //
	long long strate = comb<10, 1>::result * tpow<comb<4, 1>::result, 5>::result - comb<10, 1>::result * comb<4, 1>::result;
	long long flush = comb<4, 1>::result * comb<13, 5>::result - comb<10, 1>::result * comb<4, 1>::result;;
	long long full_house = comb<13, 1>::result * comb<4, 2>::result * comb<12, 1>::result * comb<4, 3>::result;
	long long four_card = comb<13, 1>::result * comb<48, 2>::result; //
	long long strate_flush = comb<10, 1>::result * comb<4, 1>::result - comb<1, 1>::result * comb<4, 1>::result;
	long long royal_strate_flush = comb<1, 1>::result * comb<4, 1>::result;
W

	printf("%lld/%lld\n", one_pair, total);
	printf("%lld/%lld\n", two_pair, total);
	printf("%lld/%lld\n", triple, total);
	printf("%lld/%lld\n", strate, total);
	printf("%lld/%lld\n", flush, total);
	printf("%lld/%lld\n", full_house, total);
	printf("%lld/%lld\n", strate_flush, total);
	printf("%lld/%lld\n", royal_strate_flush, total);
	
	printf("\n%lld\n%lld\n", one_pair + two_pair + triple + strate + flush + full_house + strate_flush + royal_strate_flush, total);
	return 0;
}
