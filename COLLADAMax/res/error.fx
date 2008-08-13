/*********************************************************************NVMH3****
Path:  NVSDK\Common\media\cgfx
File:  viewer_Invalid.fx

Copyright NVIDIA Corporation 2002
TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THIS SOFTWARE IS PROVIDED
*AS IS* AND NVIDIA AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES, EITHER EXPRESS
OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL NVIDIA OR ITS SUPPLIERS
BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT, OR CONSEQUENTIAL DAMAGES
WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS)
ARISING OUT OF THE USE OF OR INABILITY TO USE THIS SOFTWARE, EVEN IF NVIDIA HAS
BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.


Comments:

******************************************************************************/

float4 diffuseMaterial : Diffuse < string UIWidget = "Color"; string Space = "material";> = {1.0f, 0.0f, 0.0f, 0.4f };
float4x4 wvp : WorldViewProjection;

struct VS_OUTPUT
{
    float4 Position   : POSITION;
    float4 Diffuse    : COLOR0;
};

// vertex shader
VS_OUTPUT VS(float3 Position : POSITION)
{
    VS_OUTPUT Out = (VS_OUTPUT)0;
    Out.Position = mul(float4(Position, 1), wvp); 
    Out.Diffuse = diffuseMaterial;
   
    return Out;
}

technique t0
{
	pass p0
	{
        VertexShader = compile vs_1_1 VS();
		FillMode = WireFrame;
	}
}

