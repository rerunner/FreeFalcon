#include <d3dxmath.h>



// This function returns the Distance btw 2 points
inline	float	RED_Distance3D(D3DXVECTOR3 *V1, D3DXVECTOR3 *V2 )
{
	float	dx = V1->x - V2->x;
	float	dy = V1->y - V2->y;
	float	dz = V1->z - V2->z;

	return sqrtf( dx * dx + dy * dy + dz * dz);
}



// This function returns a vector lenght
inline	float	RED_Lenght3D(D3DXVECTOR3 *V )
{
	return sqrtf( V->x * V->x + V->y * V->y + V->z * V->z);
}



inline	D3DXVECTOR3	RED_NormalizeVector(D3DXVECTOR3 *V)
{
	D3DXVECTOR3 R;
	
	float	Norm = sqrtf(V->x * V->x + V->y * V->y + V->z * V->z);
	if(!Norm) R.x = R.y = R.z =0;
	else R.x = V->x / Norm, R.y = V->y / Norm, R.z = V->z / Norm;
	return R;
}

inline	D3DXVECTOR3	RED_CrossProduct(D3DXVECTOR3 *V1, D3DXVECTOR3 *V2 )
{
	D3DXVECTOR3 V;

	// * CALCULATE THE CROSS PRODUCT BTW CAMERA ( the origin )AND THE SL POINT *
	V.x = V1->y * V2->z - V1->z * V2->y; 
	V.y = V1->z * V2->x - V1->x * V2->z; 
	V.z = V1->x * V2->y - V1->y * V2->x; 

	return V;
}


inline	D3DXVECTOR3	RED_Normal(D3DXVECTOR3 &S0, D3DXVECTOR3 &S1 )
{
	D3DXVECTOR3 V;

	// * CALCULATE THE CROSS PRODUCT BTW S0 and S1
	V.x = S0.y * S1.z - S0.z * S1.y; 
	V.y = S0.z * S1.x - S0.x * S1.z; 
	V.z = S0.x * S1.y - S0.y * S1.x; 

	// * THE NORMALIZED CROSS PRODUCT 
	float Norm= (float)sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2));
	V.x/=Norm, V.y/=Norm, V.z/=Norm; 

	return V;
}