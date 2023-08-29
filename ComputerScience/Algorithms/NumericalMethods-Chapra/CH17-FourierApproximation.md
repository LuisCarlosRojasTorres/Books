<!-- vscode-markdown-toc -->
* 1. [Curve Fitting with Sinusoidal Functions](#CurveFittingwithSinusoidalFunctions)
* 2. [Continuous Fourier Series](#ContinuousFourierSeries)
* 3. [Frequency and Time Domains](#FrequencyandTimeDomains)
* 4. [Fourier Integral and Transform](#FourierIntegralandTransform)
* 5. [Discrete Fourier Transform DFT](#DiscreteFourierTransformDFT)
* 6. [Fast Fourier Transform FFT](#FastFourierTransformFFT)
* 7. [The Power Spectrum](#ThePowerSpectrum)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='CurveFittingwithSinusoidalFunctions'></a>Curve Fitting with Sinusoidal Functions

- A periodic function: 
``` math
f(t) = f(t+T)
```
- A general sinusoidal function: 
``` math
f(t) = A_0 + C_1 cos(\omega_0 t + \theta) \\
- \\
Where: \\
A_0 : mean \, value \\
C_1 : amplitude \\ 
\omega_0 : angular \, frequency \\
\theta : phase \, angle \\
```
- An easier to treat form of this equation is : 
``` math
C_1 cos(\omega_0 t + \theta) = C_1 [cos(\omega_0)cos(\theta) - sin(\omega_0)sin(\theta)]
```

- Replacing this we have

``` math
f(t) = A_0 + A_1 cos(\omega_0 t) + B_1 sin(\omega_0 t) \\
- \\
Where: \\
A_1= C_1 cos(\theta) \\
B_1= - C_1 sin(\theta) \\
\theta = arctan(- \frac{B_1}{A_1}) \\
C_1 = \sqrt{{A_1}^2+{B_1}^2}

```
 
##  2. <a name='ContinuousFourierSeries'></a>Continuous Fourier Series

##  3. <a name='FrequencyandTimeDomains'></a>Frequency and Time Domains

##  4. <a name='FourierIntegralandTransform'></a>Fourier Integral and Transform

##  5. <a name='DiscreteFourierTransformDFT'></a>Discrete Fourier Transform DFT

##  6. <a name='FastFourierTransformFFT'></a>Fast Fourier Transform FFT

##  7. <a name='ThePowerSpectrum'></a>The Power Spectrum