#version 330

in vec2 fragTexCoord;
out vec4 fragColor;
uniform sampler2D texture0;

uniform int numLights;
uniform vec2 lightPositions[50];


float lightRadius = 200.0;
float lightIntensity = 1.0;
vec3 lightColor = vec3(1.0, 0.8, 0.6);

void main()
{
    vec4 texelColor = texture(texture0, fragTexCoord);
    vec2 pixelPosition = vec2(gl_FragCoord.xy);
    vec3 finalColor = vec3(0.0);

    for(int i = 0; i < numLights; i++) {

        vec2 toLight = normalize(lightPositions[i] - pixelPosition);
        float distanceToLight = distance(lightPositions[i], pixelPosition);
        float attenuation = 1.0 - (distanceToLight / lightRadius);
        attenuation = max(attenuation, 0.08);
        vec3 diffuse = lightColor * lightIntensity * attenuation;
        finalColor += diffuse;
    }

    fragColor = vec4(texelColor.rgb * finalColor, texelColor.a);
}
