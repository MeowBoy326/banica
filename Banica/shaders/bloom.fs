#version 330

out vec4 outColor;

in vec2 fragTexCoord;
uniform sampler2D texture0;
uniform vec4 colDiffuse;

const vec2 size = vec2(1270, 720);   // Framebuffer size

void main()
{
    vec4 sum = vec4(0);
    vec4 source = texture(texture0, fragTexCoord);
    float bloomIntensity = 0.65;

    float xBlurSize = 2.0 / size.x;

    sum += texture(texture0, vec2(fragTexCoord.x - 4.0*xBlurSize, fragTexCoord.y)) * 0.05;
    sum += texture(texture0, vec2(fragTexCoord.x - 3.0*xBlurSize, fragTexCoord.y)) * 0.09;
    sum += texture(texture0, vec2(fragTexCoord.x - 2.0*xBlurSize, fragTexCoord.y)) * 0.12;
    sum += texture(texture0, vec2(fragTexCoord.x - xBlurSize, fragTexCoord.y)) * 0.15;
    sum += source * 0.16; 
    sum += texture(texture0, vec2(fragTexCoord.x - xBlurSize, fragTexCoord.y)) * 0.15;
    sum += texture(texture0, vec2(fragTexCoord.x - 2.0*xBlurSize, fragTexCoord.y)) * 0.12;
    sum += texture(texture0, vec2(fragTexCoord.x - 3.0*xBlurSize, fragTexCoord.y)) * 0.09;
    sum += texture(texture0, vec2(fragTexCoord.x - 4.0*xBlurSize, fragTexCoord.y)) * 0.05;

    float yBlurSize = 2.0 / size.y;

    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y - 4.0*yBlurSize)) * 0.05;
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y - 2.0*yBlurSize)) * 0.12;
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y - 3.0*yBlurSize)) * 0.09;
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y - yBlurSize)) * 0.15;
    sum += source * 0.16; 
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y + yBlurSize)) * 0.15;
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y + 2.0*yBlurSize)) * 0.12;
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y + 3.0*yBlurSize)) * 0.09;
    sum += texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y + 4.0*yBlurSize)) * 0.05;


    outColor = sum * bloomIntensity * texture(texture0, fragTexCoord);
}