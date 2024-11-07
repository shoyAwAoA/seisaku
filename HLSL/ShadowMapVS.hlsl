#include"Lambert.hlsli"


cbuffer CbScene : register(b0)
{
    row_major float4x4 lightViewProjection;
};

float4 main(
float4 position : POSITION,
float4 boneWeights:BONE_WEIGHTS,
float4 boneIndices:BONE_INDICES) : SV_POSITION
{
    position = LambertPosition(position, boneWeights, boneIndices);
    
    return mul(position, lightViewProjection);

}