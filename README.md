import numpy as np
import matplotlib.pyplot as plt


class DiscreteSignal:
    def __init__(self, INF):
        self.INF = INF
        self.values = np.zeros(INF * 2 + 1)
        self.time_index = INF

    def set_value_at_time(self, time, value):
        self.values[time + self.time_index] = value

    def shift_signal(self, shift):
        new_signal = DiscreteSignal(self.INF)
        if shift > 0:
            new_signal.values[shift:] = self.values[:-shift]
        elif shift < 0:  # Add this condition for negative shifts
            new_signal.values[:shift] = self.values[-shift:]
        else:
            new_signal = self

        return new_signal

    def multiply(self, other):
        new_signal = DiscreteSignal(self.INF)
        new_signal.values = np.multiply(self.values, other.values)

        return new_signal

    def add(self, other):
        new_signal = DiscreteSignal(self.INF)
        new_signal.values = self.values + other.values

        return new_signal

    def multiply_const_factor(self, scaler):
        new_signal = DiscreteSignal(self.INF)
        new_signal.values = scaler * self.values

        return new_signal

    # def plot(self):
    #     plt.figure(figsize=(8, 3))
    #     plt.stem(np.arange(-self.INF, self.INF + 1), self.values)
    #     plt.xlabel('n (Time Index)')
    #     plt.ylabel('x[n]')
    #     plt.ylim(-1, 5)
    #     plt.grid(True)

    def plot(self, title=None, x_label='n (Time Index)', y_label='x[n]', y_range=(-1, 5)):
        plt.figure(figsize=(8, 3))
        plt.stem(np.arange(-self.INF, self.INF + 1), self.values)
        plt.xlabel(x_label)
        plt.ylabel(y_label)
        plt.ylim(y_range)
        plt.xticks(np.arange(-self.INF, self.INF + 1, 1))  # Added this line
        plt.grid(True)
        if title:
            plt.title(title)

    def plot_ax(self, ax, title=None, x_label='n (Time Index)', y_label='x[n]', y_range=(-1, 5)):
        ax.stem(np.arange(-self.INF, self.INF + 1), self.values, basefmt=" ")
        ax.set_xlabel(x_label)
        ax.set_ylabel(y_label)
        ax.set_ylim(y_range)
        ax.grid(True)
        if title:
            ax.set_title(title)


class LTI_Discrete:

    def __init__(self, impulse_response):
        self.impulse_response = impulse_response

    # def linear_combination_of_impulses(self, input_signal):
    #
    #     unit_impulses = []
    #     coefficients = []
    #
    #     for i, value in enumerate(input_signal.values):
    #         impulse = DiscreteSignal(input_signal.INF)
    #         impulse.set_value_at_time(i - input_signal.time_index, 1)
    #         unit_impulses.append(impulse)
    #         coefficients.append(value)
    #     return unit_impulses, np.array(coefficients)
    def linear_combination_of_impulses(self, input_signal):

        unit_impulses = []
        coefficients = []

        for i, value in enumerate(input_signal.values):
            impulse = DiscreteSignal(input_signal.INF)
            impulse.set_value_at_time(i - input_signal.INF, 1)  # Corrected time index
            unit_impulses.append(impulse)
            coefficients.append(value)
        return unit_impulses, np.array(coefficients)

    def output(self, input_signal):
        unit_impulses, coefficients = self.linear_combination_of_impulses(input_signal)

        impulse_responses = []
        output_signal = DiscreteSignal(input_signal.INF)
        a = 0
        for unit_impulse, value in zip(unit_impulses, coefficients):
            shifted_impulse_response = self.impulse_response.shift_signal(a-unit_impulse.time_index)
            print(a-unit_impulse.time_index, value)
            impulse_responses.append(shifted_impulse_response)
            scaled_impulse = shifted_impulse_response.multiply_const_factor(value)
            output_signal = output_signal.add(scaled_impulse)
            a = a + 1

        return output_signal, impulse_responses, coefficients


def plot_impulses(impulses, sum_signal, suptitle, which_impulse, plot_name="Impulses"):
    total_impulse = len(impulses)
    rows = (total_impulse + 2) // 3
    cols = min(total_impulse, 3)

    fig, axs = plt.subplots(rows, cols, figsize=(cols * 3, rows * 3))

    # Correctly handle the case with only one subplot
    if rows == 1 and cols == 1:
        axs = [axs]
    else:
        axs = axs.flatten()

    # Plot the individual impulse responses
    for i, impulse in enumerate(impulses):
        if which_impulse == "input impulse":
            impulse.plot_ax(ax=axs[i], title=fr'$\delta[n  -  ({i - impulse.INF})] \times[{i - impulse.INF}]$',
                            y_range=(-1, 3))
        else:
            impulse.plot_ax(ax=axs[i], title=fr'$h[n - ({i - impulse.INF})] \ast \times[{i - impulse.INF}]$',
                            y_range=(-1, 3))

    # Plot the sum of the impulse responses if there are multiple impulses
    if len(impulses) > 1:
        sum_signal.plot_ax(ax=axs[-1], title="Sum", y_range=(-1, 3))

    plt.tight_layout()

    fig.suptitle(suptitle, fontsize=14)
    plt.subplots_adjust(top=.9)


def impulse_signals(LTI_signal, input_signal):
    impulses, coefficients = LTI_signal.linear_combination_of_impulses(input_signal)

    unit_impulses = []
    sum_signal = DiscreteSignal(input_signal.INF)

    for impulse, coefficient in zip(impulses, coefficients):
        new_signal = impulse.multiply_const_factor(coefficient)
        sum_signal = sum_signal.add(new_signal)
        unit_impulses.append(new_signal)

    plot_impulses(unit_impulses, sum_signal, suptitle="Impulses multiplied by coefficients",
                  which_impulse="input impulse", plot_name="Impulses")


def show_output(lti, input_signal):
    # Find the output of the system
    output_signal, shifted_impulse_responses, coefficients = lti.output(input_signal)

    # Store impulse responses that are correctly scaled and shifted
    impulse_responses = []

    for idx, (shifted_impulse_response, coefficient) in enumerate(zip(shifted_impulse_responses, coefficients)):
        # Scale the shifted impulse response by the coefficient of the input
        if coefficient != 0:
            scaled_impulse_response = shifted_impulse_response.multiply_const_factor(coefficient)
            impulse_responses.append(scaled_impulse_response)
        else:
            # Add a blank signal if the coefficient is zero to maintain index alignment
            blank_signal = DiscreteSignal(input_signal.INF)
            impulse_responses.append(blank_signal)

    # Plot the output and the impulse responses
    plot_impulses(impulse_responses, output_signal, suptitle="Response of Input Signal",
                  which_impulse="impulse response",
                  plot_name="Impulse_Response")


# Continous Signal !!

class ContinuousSignal:

    def __init__(self, func,start=None):
        """Initializes the signal with a given funnc"""
        self.func = func
        self.start = start

    def shift(self, shift):
        """Returns a new ContinuousSignal instance with the shifted signal x(n - shift)."""

        def shifted_func(t):
            return self.func(t - shift)

        return ContinuousSignal(shifted_func)

    def add(self, other):
        """Returns a new ContinuousSignal instance representing the sum of two signals."""
        return ContinuousSignal(lambda t: self.func(t) + other.func(t))

    def multiply(self, other):
        """Returns a new ContinuousSignal instance representing element-wise multiplication."""
        return ContinuousSignal(lambda t: self.func(t) * other.func(t))

    def multiply_const_factor(self, scaler):
        """Returns a new ContinuousSignal instance with the signal multiplied by a constant factor."""
        return ContinuousSignal(lambda t: self.func(t) * scaler)

    def plot(self, figsize=(8, 3), t_range=(-3,3),y_range=(-.1,1.3), title="Continuous Signal", x_label='t (Time)',
             y_label='x(t)', saveTo=None):
        """Plots the signal using matplotlib."""

        # create a new figure
        plt.figure(figsize=figsize)

        # set x-axis times
        t = np.linspace(t_range[0], t_range[1], 1000)
        plt.xticks(np.arange(t_range[0], t_range[1], 1))

        # set y-axis values
        y = self.func(t)
        # plt.yticks(np.arange(y_range[0], y_range[1], .5))
        plt.ylim(y_range)

        # plot the signal (X,Y)
        plt.plot(t, y)

        # set title
        plt.title(title)
        # set x_label
        plt.xlabel(x_label)
        # set y_label
        plt.ylabel(y_label)

        plt.grid(True)

        if saveTo is not None:
            plt.savefig(saveTo)


    #helper function
    def plot_ax(self, ax=None, figsize=(8, 3), t_range=(-3, 3), y_range=(-.1, 1.3), title="Continuous Signal",
                x_label='t (Time)', y_label='x(t)'):

        if ax is None:
            _, ax = plt.subplots(figsize=figsize)

        t = np.linspace(t_range[0], t_range[1], 1000)
        ax.set_xticks(np.arange(t_range[0], t_range[1] + 1, 1))

        # set y-axis values
        y = self.func(t)
        ax.set_yticks(np.arange(y_range[0], y_range[1],.6))
        ax.set_ylim(y_range)

        # plot the signal (X,Y)
        ax.plot(t, y)

        ax.set_title(title)
        ax.set_xlabel(x_label)
        ax.set_ylabel(y_label)

        ax.grid(True)

        return ax

    def set_start(self, start):
        self.start = start

    def __str__(self):
        return f"This is a continuous signal defined by the function {self.func}"

class LtiContinuous:
    """Initializes the system with the system impulse response"""

    def __init__(self, impulse_response=None, INF=5):
        self.impulse_response = impulse_response
        self.INF = INF


    def linear_combination_of_impulses(self, input_signal, delta):
        impulses = []

        tau = np.arange(-self.INF * delta, (self.INF + 1) * delta, delta)
        tau = np.round(tau, decimals=10)
        x_t = input_signal.func(tau)
        coefficient = x_t * delta

        n = len(tau)
        for i in range(n - 1):
            def make_impulse(start, end):
                return lambda t: np.where((t >= start) & (t < end), 1 / delta, 0)

            impulse = ContinuousSignal(make_impulse(tau[i], tau[i + 1]), tau[i])
            impulses.append(impulse)

        return impulses, coefficient

    def output_approx(self, input_signal, delta):
        output_signal = ContinuousSignal(lambda t: 0 * t)
        impulses, coefficients = self.linear_combination_of_impulses(input_signal, delta)
        impulse_responses = []

        for i, c in zip(impulses, coefficients):
            shifted_impulse_response = self.impulse_response.shift(i.start)
            shifted_impulse_response.set_start(i.start)
            impulse_responses.append(shifted_impulse_response)
            scaled_response = shifted_impulse_response.multiply_const_factor(c)
            output_signal = output_signal.add(scaled_response)

        return output_signal, impulse_responses, coefficients


def plot_impulse(unit_impulses, reconstructed_signal, which_impulse="input impulse", suptitle="", delta=.5,
                 plot_name="plots"):
    num_impulses = len(unit_impulses)
    rows = (num_impulses + 3) // 3  # Calculate number of rows needed
    cols = 3  # Number of columns

    fig, axs = plt.subplots(rows, cols, figsize=(cols * 3, rows * 3))
    axs = axs.flatten()
    size_of_subplots = len(axs)
    size_of_impulses = len(unit_impulses)

    # Plot the individual impulse responses
    for i, impulse in enumerate(unit_impulses):
        # Inside the plot_impulse function
        if which_impulse == "input impulse":
            title = fr'$\delta(t - ({round((impulse.start) / delta)}\nabla)) \times({round((impulse.start) / delta)}\nabla)\nabla$'
        else:
            title = fr'$h(t - ({round((impulse.start) / delta)}\nabla)) \ast \times({round((impulse.start) / delta)}\nabla)\nabla$'

        impulse.plot_ax(ax=axs[i], title=title, y_range=(-.1, 1.1))

    reconstructed_signal.plot_ax(ax=axs[-(size_of_subplots - size_of_impulses)], title="Output=Sum", y_range=(-.1, 1.3))

    fig.suptitle(suptitle, fontsize=14)
    plt.subplots_adjust(top=.9)

    plt.tight_layout()


def show_linear(lti_system, input_signal, delta):
    impulses, coefficients = lti_system.linear_combination_of_impulses(input_signal, delta)

    unit_impulses = []
    reconstructed_signal = ContinuousSignal(lambda t: 0 * t)

    for shifted_unit_impulse, coefficient in zip(impulses, coefficients):
        scaled_impulse = shifted_unit_impulse.multiply_const_factor(coefficient)
        scaled_impulse.set_start(shifted_unit_impulse.start)
        unit_impulses.append(scaled_impulse)
        reconstructed_signal = reconstructed_signal.add(scaled_impulse)

    plot_impulse(unit_impulses, reconstructed_signal, which_impulse="input impulse",
                 suptitle="Impulses multiplied by coefficients", delta=delta, plot_name="input impulses")


def show_output_approx(lti_system, input_signal, delta):
    output, shifted_impulse_responses, coefficients = lti_system.output_approx(input_signal, delta)

    impulse_responses = []
    for shifted_impulse_response, coefficient in zip(shifted_impulse_responses, coefficients):
        scaled_impulse_response = shifted_impulse_response.multiply_const_factor(coefficient)
        scaled_impulse_response.set_start(shifted_impulse_response.start)
        # print(shifted_impulse_response.start)
        # shifted_impulse_response.plot(title="Shifted Impulse Response")
        impulse_responses.append(scaled_impulse_response)

    plot_impulse(impulse_responses, output, which_impulse="output impulse",
                 suptitle="Response of Impulse Signal", delta=delta, plot_name="output_impulses")


def show_delta_comparison_input_plots():
    lti_system = LtiContinuous(INF=320)

    input_signal = ContinuousSignal(lambda t: np.exp(-t) * (t >= 0))

    # Create a 2x2 subplot
    fig, axs = plt.subplots(2, 2, figsize=(10, 10))
    fig.suptitle("Reconstructed Signals for Different Delta Values", fontsize=16)

    # Define delta values
    delta_values = [0.5, 0.1, 0.05, 0.01]

    # Time range for plotting
    t_range = np.linspace(-3.1, 3.1, 1000)

    # Plot for each delta value
    for i, delta in enumerate(delta_values):
        row = i // 2
        col = i % 2

        # Get impulses and coefficients
        imp, co = lti_system.linear_combination_of_impulses(input_signal, delta)

        # Reconstruct the signal
        reconstructed_signal = ContinuousSignal(lambda t: 0 * t)
        for impulse, coeff in zip(imp, co):
            new_impulse = impulse.multiply_const_factor(coeff)
            reconstructed_signal = reconstructed_signal.add(new_impulse)

        # Plot original and reconstructed signals
        axs[row, col].plot(t_range, reconstructed_signal.func(t_range), label='Reconstructed ')
        axs[row, col].plot(t_range, input_signal.func(t_range), label='x(t)')

        axs[row, col].set_title(fr'$\nabla = {delta}$')
        axs[row, col].set_ylim(-0.1, 1.1)
        axs[row, col].set_xlim(-3.1, 3.1)
        axs[row, col].legend()
        axs[row, col].grid(True)
        axs[row, col].set_xlabel('t(Time)')
        axs[row, col].set_ylabel('x(t)')

    # Adjust layout
    plt.tight_layout()


def show_delta_comparison_output_plots():
    impulse_response = ContinuousSignal(func=(lambda t: np.where(t >= 0, 1, 0)))
    input_signal = ContinuousSignal(func=(lambda t: np.exp(-t) * (t >= 0)))

    # Create LTI system
    lti_system = LtiContinuous(impulse_response, INF=320)

    # Create a 2x2 subplot
    fig, axs = plt.subplots(2, 2, figsize=(10, 10))
    fig.suptitle(r'Approximate output as $\nabla$ tends to 0', fontsize=10)

    # delta values
    delta_values = [0.5, 0.1, 0.05, 0.01]

    # Time range for plotting
    t_range = np.linspace(-3, 3, 1000)

    # The reference function calulated by hand (1-e^(-t))u(t))
    reference_func = lambda t: (1 - np.exp(-t)) * (np.where(t >= 0, 1, 0))

    # Plot for each delta value
    for i, delta in enumerate(delta_values):
        row = i // 2
        col = i % 2

        # Get output signal
        out, _, _ = lti_system.output_approx(input_signal, delta)

        # Plot output signal and reference function
        axs[row, col].plot(t_range, out.func(t_range), label='y_approx(t)')
        axs[row, col].plot(t_range, reference_func(t_range), label='y(t)=(1-e^(-t))u(t)')

        axs[row, col].set_title(fr'$\nabla = {delta}$')
        axs[row, col].set_ylim(-.05, 1.3)
        axs[row, col].set_xlim(-3.1, 3.1)
        axs[row, col].legend()
        axs[row, col].grid(True)
        axs[row, col].set_xlabel('t(Time)')
        axs[row, col].set_ylabel('x(t)')

    # Adjust layout
    plt.tight_layout()


def main():

    # Discrete !

    impulse_response = DiscreteSignal(5)
    impulse_response.set_value_at_time(0, 1)
    impulse_response.set_value_at_time(1, 1)
    impulse_response.set_value_at_time(2, 1)
    impulse_response.plot(title=f"Figure 1: Impulse Response of the system,INF= {impulse_response.INF}")

    input_signal = DiscreteSignal(5)
    input_signal.set_value_at_time(0, .5)
    input_signal.set_value_at_time(1, 2)
    input_signal.plot(title=f"Figure 2: Input Signal,INF= {input_signal.INF}")

    lti = LTI_Discrete(impulse_response)

    impulse_signals(lti, input_signal)
    show_output(lti, input_signal)

    ## Continous !

    impulse_response = ContinuousSignal(func=(lambda t: np.where(t >= 0, 1, 0)))
    impulse_response.plot(title="Impulse Response", t_range=(-3, 3), y_range=(-.1, 1.1))
    # Define the input signal
    input_signal = ContinuousSignal(func=(lambda t: np.exp(-t) * (t >= 0)))
    input_signal.plot(title="Input Signal", t_range=(-3, 3), y_range=(-.1, 1.1))

    # Create LTI system
    lti_system = LtiContinuous(impulse_response, INF=6)

    # show the unit_impulse multiplied by their coefficients and reconstructed signal
    show_linear(lti_system, input_signal, .5)
    # show the Impulse response multiplied by their coefficients and output signal
    show_output_approx(lti_system, input_signal, .5)
    # show delta_comparison_input_plots
    show_delta_comparison_input_plots()
    # show delta_comparison_output_plots
    show_delta_comparison_output_plots()
    plt.show()


if __name__ == "__main__":
    main()
